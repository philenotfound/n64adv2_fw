//////////////////////////////////////////////////////////////////////////////////
//
// This file is part of the N64 RGB/YPbPr DAC project.
//
// Copyright (C) 2015-2023 by Peter Bartmann <borti4938@gmail.com>
//
// N64 RGB/YPbPr DAC is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//////////////////////////////////////////////////////////////////////////////////
//
// Company:  Circuit-Board.de
// Engineer: borti4938
//
// Module Name:    n64_vinfo_ext
// Project Name:   N64 Advanced RGB/YPbPr DAC Mod
// Target Devices: universial
// Tool versions:  Altera Quartus Prime
// Description:    extracts video info from input
//
//////////////////////////////////////////////////////////////////////////////////


module n64_vinfo_ext(
  VCLK,
  nRST,
  nVDSYNC,

  Sync_pre,
  Sync_cur,

  vinfo_o
);

`include "../../lib/n64adv_vparams.vh"

input VCLK;
input nRST;
input nVDSYNC;

input  [3:0] Sync_pre;
input  [3:0] Sync_cur;

output [2:0] vinfo_o;   // order: vdata_detected,palmode,n64_480i


// some pre-assignments

wire negedge_nVSYNC =  Sync_pre[3] & !Sync_cur[3];
wire negedge_nHSYNC =  Sync_pre[1] & !Sync_cur[1];


// check for video data running at all
// ===================================

reg [2:0] dsclk_cnt = 3'd0;
reg [8:0] vclk_cnt = 9'd0;
reg [11:0] hclk_cnt = 12'd0;
reg vdata_detected = 1'b0;

always @(posedge VCLK or negedge nRST)
  if (!nRST) begin
    dsclk_cnt <= 4'd0;
    vclk_cnt <= 9'd0;
    hclk_cnt <= 12'd0;
    vdata_detected <= 1'b0;
  end else begin
    if (&dsclk_cnt | &vclk_cnt | &hclk_cnt) // clock count saturated - probably no video input running
      vdata_detected <= 1'b0;
    
    if (!nVDSYNC & negedge_nVSYNC & negedge_nHSYNC)
      vdata_detected <= 1'b1;
    
    if (!nVDSYNC)
      dsclk_cnt <= 3'd0;
    else
      dsclk_cnt <= &dsclk_cnt ? dsclk_cnt : dsclk_cnt + 3'd1;  // saturate at 7
    
    if (negedge_nVSYNC)
      vclk_cnt <= 9'd0;
    else if (!nVDSYNC & negedge_nHSYNC)
      vclk_cnt <= &vclk_cnt ? vclk_cnt : vclk_cnt + 9'd1;  // saturate at 512
    else
      vclk_cnt <= vclk_cnt;
    
    if (negedge_nHSYNC)
      hclk_cnt <= 12'd0;
    else
      hclk_cnt <= &hclk_cnt ? hclk_cnt : hclk_cnt + 12'd1;  // saturate at 4095
  end


// estimation of 240p/288p
// =======================

reg field_id  = 1'b1; // 0 = even frame, 1 = odd frame; 240p: only even or only odd frames; 480i: even and odd frames
reg n64_480i  = 1'b1; // 0 = 240p/288p , 1= 480i/576i

always @(posedge VCLK or negedge nRST)
  if (!nRST) begin
    field_id  <= 1'b1;
    n64_480i <= 1'b1;
  end else begin
    if (!nVDSYNC) begin
      if (negedge_nVSYNC) begin 
        field_id <= negedge_nHSYNC;
        n64_480i <= field_id ^ negedge_nHSYNC;
      end
    end
  end

// determine vmode
// ===============

reg [1:0] line_cnt = 2'b00; // PAL: line_cnt[1:0] == 0x ; NTSC: line_cnt[1:0] = 1x
reg        palmode = 1'b0;  // PAL: palmode == 1        ; NTSC: palmode == 0

always @(posedge VCLK or negedge nRST)
  if (!nRST) begin
    line_cnt <= 2'b00;
    palmode  <= 1'b0;
  end else begin
    if (!nVDSYNC) begin
      if(negedge_nVSYNC) begin // reset line_cnt and set palmode
        line_cnt <= 2'b00;
        palmode  <= ~line_cnt[1];
      end else if(negedge_nHSYNC) // new line -> increase line_cnt
        line_cnt <= line_cnt + 1'b1;
    end
  end


// pack vinfo_o vector
// ===================

assign vinfo_o = {vdata_detected,palmode,n64_480i};

endmodule
