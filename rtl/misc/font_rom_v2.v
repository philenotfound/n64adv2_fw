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
// Module Name:    font_rom_v2
// Project Name:   N64 Advanced RGB/YPbPr DAC Mod
// Target Devices: Max10, Cyclone IV and Cyclone 10 LP devices
// Tool versions:  Altera Quartus Prime
// Description:    simple line-multiplying
//
// Features: ip independent implementation of font rom
//
// This file is auto generated by script/font2rom.m
//
//////////////////////////////////////////////////////////////////////////////////


module font_rom_v2(
  CLK,
  nRST,
  char_addr,
  char_line,
  rden,
  rddata
);

input       CLK;
input       nRST;
input [6:0] char_addr;
input [3:0] char_line;
input       rden;

output reg [7:0] rddata = 8'h0;


reg [7:0] rddata_opt [0:3];
initial begin
  rddata_opt[0] = 8'h0;
  rddata_opt[1] = 8'h0;
  rddata_opt[2] = 8'h0;
  rddata_opt[3] = 8'h0;
end
reg [1:0] lsb_addr_r = 2'h00;
reg           rden_r = 1'b0;

always @(posedge CLK or negedge nRST)
  if (!nRST) begin
    rddata <= 8'h0;
    rddata_opt[0] = 8'h0;
    rddata_opt[1] = 8'h0;
    rddata_opt[2] = 8'h0;
    rddata_opt[3] = 8'h0;
    lsb_addr_r <= 2'h00;
    rden_r <= 1'b0;
  end else begin
    lsb_addr_r <= char_addr[1:0];
    rden_r <= rden;
  
    if (rden) begin
      case ({char_line,char_addr[6:2]})
        0024:    rddata_opt[0] <= 012;
        0036:    rddata_opt[0] <= 064;
        0037:    rddata_opt[0] <= 028;
        0042:    rddata_opt[0] <= 048;
        0044:    rddata_opt[0] <= 062;
        0045:    rddata_opt[0] <= 048;
        0046:    rddata_opt[0] <= 030;
        0047:    rddata_opt[0] <= 048;
        0048:    rddata_opt[0] <= 062;
        0049:    rddata_opt[0] <= 031;
        0050:    rddata_opt[0] <= 051;
        0051:    rddata_opt[0] <= 015;
        0052:    rddata_opt[0] <= 063;
        0053:    rddata_opt[0] <= 063;
        0054:    rddata_opt[0] <= 051;
        0056:    rddata_opt[0] <= 012;
        0057:    rddata_opt[0] <= 056;
        0058:    rddata_opt[0] <= 007;
        0059:    rddata_opt[0] <= 030;
        0068:    rddata_opt[0] <= 096;
        0069:    rddata_opt[0] <= 034;
        0074:    rddata_opt[0] <= 024;
        0076:    rddata_opt[0] <= 099;
        0077:    rddata_opt[0] <= 056;
        0078:    rddata_opt[0] <= 051;
        0079:    rddata_opt[0] <= 024;
        0080:    rddata_opt[0] <= 099;
        0081:    rddata_opt[0] <= 054;
        0082:    rddata_opt[0] <= 051;
        0083:    rddata_opt[0] <= 006;
        0084:    rddata_opt[0] <= 102;
        0085:    rddata_opt[0] <= 045;
        0086:    rddata_opt[0] <= 051;
        0087:    rddata_opt[0] <= 001;
        0088:    rddata_opt[0] <= 024;
        0089:    rddata_opt[0] <= 048;
        0090:    rddata_opt[0] <= 006;
        0091:    rddata_opt[0] <= 024;
        0093:    rddata_opt[0] <= 004;
        0100:    rddata_opt[0] <= 112;
        0101:    rddata_opt[0] <= 093;
        0106:    rddata_opt[0] <= 012;
        0108:    rddata_opt[0] <= 115;
        0109:    rddata_opt[0] <= 060;
        0110:    rddata_opt[0] <= 051;
        0111:    rddata_opt[0] <= 012;
        0112:    rddata_opt[0] <= 099;
        0113:    rddata_opt[0] <= 102;
        0114:    rddata_opt[0] <= 051;
        0115:    rddata_opt[0] <= 006;
        0116:    rddata_opt[0] <= 102;
        0117:    rddata_opt[0] <= 012;
        0118:    rddata_opt[0] <= 051;
        0119:    rddata_opt[0] <= 003;
        0121:    rddata_opt[0] <= 048;
        0122:    rddata_opt[0] <= 006;
        0123:    rddata_opt[0] <= 024;
        0125:    rddata_opt[0] <= 006;
        0132:    rddata_opt[0] <= 124;
        0133:    rddata_opt[0] <= 069;
        0138:    rddata_opt[0] <= 006;
        0140:    rddata_opt[0] <= 123;
        0141:    rddata_opt[0] <= 054;
        0142:    rddata_opt[0] <= 051;
        0143:    rddata_opt[0] <= 006;
        0144:    rddata_opt[0] <= 123;
        0145:    rddata_opt[0] <= 102;
        0146:    rddata_opt[0] <= 051;
        0147:    rddata_opt[0] <= 006;
        0148:    rddata_opt[0] <= 102;
        0149:    rddata_opt[0] <= 012;
        0150:    rddata_opt[0] <= 030;
        0151:    rddata_opt[0] <= 006;
        0153:    rddata_opt[0] <= 062;
        0154:    rddata_opt[0] <= 054;
        0155:    rddata_opt[0] <= 024;
        0156:    rddata_opt[0] <= 059;
        0157:    rddata_opt[0] <= 063;
        0158:    rddata_opt[0] <= 099;
        0164:    rddata_opt[0] <= 127;
        0165:    rddata_opt[0] <= 069;
        0170:    rddata_opt[0] <= 006;
        0172:    rddata_opt[0] <= 107;
        0173:    rddata_opt[0] <= 051;
        0174:    rddata_opt[0] <= 030;
        0175:    rddata_opt[0] <= 003;
        0176:    rddata_opt[0] <= 123;
        0177:    rddata_opt[0] <= 102;
        0178:    rddata_opt[0] <= 063;
        0179:    rddata_opt[0] <= 006;
        0180:    rddata_opt[0] <= 062;
        0181:    rddata_opt[0] <= 012;
        0182:    rddata_opt[0] <= 012;
        0183:    rddata_opt[0] <= 012;
        0185:    rddata_opt[0] <= 051;
        0186:    rddata_opt[0] <= 110;
        0187:    rddata_opt[0] <= 024;
        0188:    rddata_opt[0] <= 102;
        0189:    rddata_opt[0] <= 006;
        0190:    rddata_opt[0] <= 054;
        0196:    rddata_opt[0] <= 124;
        0197:    rddata_opt[0] <= 069;
        0202:    rddata_opt[0] <= 006;
        0204:    rddata_opt[0] <= 111;
        0205:    rddata_opt[0] <= 127;
        0206:    rddata_opt[0] <= 051;
        0207:    rddata_opt[0] <= 006;
        0208:    rddata_opt[0] <= 123;
        0209:    rddata_opt[0] <= 102;
        0210:    rddata_opt[0] <= 051;
        0211:    rddata_opt[0] <= 070;
        0212:    rddata_opt[0] <= 006;
        0213:    rddata_opt[0] <= 012;
        0214:    rddata_opt[0] <= 030;
        0215:    rddata_opt[0] <= 024;
        0217:    rddata_opt[0] <= 051;
        0218:    rddata_opt[0] <= 102;
        0219:    rddata_opt[0] <= 024;
        0220:    rddata_opt[0] <= 102;
        0221:    rddata_opt[0] <= 006;
        0222:    rddata_opt[0] <= 028;
        0228:    rddata_opt[0] <= 112;
        0229:    rddata_opt[0] <= 093;
        0234:    rddata_opt[0] <= 012;
        0236:    rddata_opt[0] <= 103;
        0237:    rddata_opt[0] <= 048;
        0238:    rddata_opt[0] <= 051;
        0239:    rddata_opt[0] <= 012;
        0240:    rddata_opt[0] <= 003;
        0241:    rddata_opt[0] <= 102;
        0242:    rddata_opt[0] <= 051;
        0243:    rddata_opt[0] <= 102;
        0244:    rddata_opt[0] <= 006;
        0245:    rddata_opt[0] <= 012;
        0246:    rddata_opt[0] <= 051;
        0247:    rddata_opt[0] <= 048;
        0249:    rddata_opt[0] <= 051;
        0250:    rddata_opt[0] <= 102;
        0251:    rddata_opt[0] <= 024;
        0252:    rddata_opt[0] <= 102;
        0253:    rddata_opt[0] <= 006;
        0254:    rddata_opt[0] <= 028;
        0260:    rddata_opt[0] <= 096;
        0261:    rddata_opt[0] <= 034;
        0266:    rddata_opt[0] <= 024;
        0267:    rddata_opt[0] <= 028;
        0268:    rddata_opt[0] <= 099;
        0269:    rddata_opt[0] <= 048;
        0270:    rddata_opt[0] <= 051;
        0271:    rddata_opt[0] <= 024;
        0272:    rddata_opt[0] <= 003;
        0273:    rddata_opt[0] <= 054;
        0274:    rddata_opt[0] <= 051;
        0275:    rddata_opt[0] <= 102;
        0276:    rddata_opt[0] <= 006;
        0277:    rddata_opt[0] <= 012;
        0278:    rddata_opt[0] <= 051;
        0279:    rddata_opt[0] <= 096;
        0281:    rddata_opt[0] <= 051;
        0282:    rddata_opt[0] <= 102;
        0283:    rddata_opt[0] <= 024;
        0284:    rddata_opt[0] <= 102;
        0285:    rddata_opt[0] <= 054;
        0286:    rddata_opt[0] <= 054;
        0292:    rddata_opt[0] <= 064;
        0293:    rddata_opt[0] <= 028;
        0298:    rddata_opt[0] <= 048;
        0299:    rddata_opt[0] <= 028;
        0300:    rddata_opt[0] <= 062;
        0301:    rddata_opt[0] <= 120;
        0302:    rddata_opt[0] <= 030;
        0303:    rddata_opt[0] <= 048;
        0304:    rddata_opt[0] <= 062;
        0305:    rddata_opt[0] <= 031;
        0306:    rddata_opt[0] <= 051;
        0307:    rddata_opt[0] <= 127;
        0308:    rddata_opt[0] <= 015;
        0309:    rddata_opt[0] <= 030;
        0310:    rddata_opt[0] <= 051;
        0311:    rddata_opt[0] <= 064;
        0313:    rddata_opt[0] <= 110;
        0314:    rddata_opt[0] <= 103;
        0315:    rddata_opt[0] <= 126;
        0316:    rddata_opt[0] <= 062;
        0317:    rddata_opt[0] <= 028;
        0318:    rddata_opt[0] <= 099;
        0331:    rddata_opt[0] <= 006;
        0348:    rddata_opt[0] <= 006;
        0380:    rddata_opt[0] <= 015;
        default: rddata_opt[0] <= 000;
      endcase

      case ({char_line,char_addr[6:2]})
        0036:    rddata_opt[1] <= 001;
        0040:    rddata_opt[1] <= 012;
        0042:    rddata_opt[1] <= 006;
        0044:    rddata_opt[1] <= 008;
        0045:    rddata_opt[1] <= 063;
        0046:    rddata_opt[1] <= 030;
        0048:    rddata_opt[1] <= 012;
        0049:    rddata_opt[1] <= 127;
        0050:    rddata_opt[1] <= 030;
        0051:    rddata_opt[1] <= 099;
        0052:    rddata_opt[1] <= 028;
        0053:    rddata_opt[1] <= 051;
        0054:    rddata_opt[1] <= 051;
        0055:    rddata_opt[1] <= 060;
        0058:    rddata_opt[1] <= 024;
        0068:    rddata_opt[1] <= 003;
        0072:    rddata_opt[1] <= 030;
        0074:    rddata_opt[1] <= 012;
        0076:    rddata_opt[1] <= 012;
        0077:    rddata_opt[1] <= 003;
        0078:    rddata_opt[1] <= 051;
        0080:    rddata_opt[1] <= 030;
        0081:    rddata_opt[1] <= 070;
        0082:    rddata_opt[1] <= 012;
        0083:    rddata_opt[1] <= 119;
        0084:    rddata_opt[1] <= 054;
        0085:    rddata_opt[1] <= 051;
        0086:    rddata_opt[1] <= 051;
        0087:    rddata_opt[1] <= 048;
        0090:    rddata_opt[1] <= 024;
        0099:    rddata_opt[1] <= 099;
        0100:    rddata_opt[1] <= 007;
        0104:    rddata_opt[1] <= 030;
        0105:    rddata_opt[1] <= 035;
        0106:    rddata_opt[1] <= 024;
        0108:    rddata_opt[1] <= 015;
        0109:    rddata_opt[1] <= 003;
        0110:    rddata_opt[1] <= 051;
        0112:    rddata_opt[1] <= 051;
        0113:    rddata_opt[1] <= 006;
        0114:    rddata_opt[1] <= 012;
        0115:    rddata_opt[1] <= 127;
        0116:    rddata_opt[1] <= 099;
        0117:    rddata_opt[1] <= 051;
        0118:    rddata_opt[1] <= 051;
        0119:    rddata_opt[1] <= 048;
        0131:    rddata_opt[1] <= 054;
        0132:    rddata_opt[1] <= 031;
        0136:    rddata_opt[1] <= 030;
        0137:    rddata_opt[1] <= 051;
        0138:    rddata_opt[1] <= 048;
        0140:    rddata_opt[1] <= 012;
        0141:    rddata_opt[1] <= 003;
        0142:    rddata_opt[1] <= 051;
        0143:    rddata_opt[1] <= 126;
        0144:    rddata_opt[1] <= 051;
        0145:    rddata_opt[1] <= 038;
        0146:    rddata_opt[1] <= 012;
        0147:    rddata_opt[1] <= 127;
        0148:    rddata_opt[1] <= 099;
        0149:    rddata_opt[1] <= 051;
        0150:    rddata_opt[1] <= 051;
        0151:    rddata_opt[1] <= 048;
        0152:    rddata_opt[1] <= 030;
        0153:    rddata_opt[1] <= 030;
        0154:    rddata_opt[1] <= 030;
        0155:    rddata_opt[1] <= 063;
        0156:    rddata_opt[1] <= 110;
        0157:    rddata_opt[1] <= 051;
        0158:    rddata_opt[1] <= 102;
        0163:    rddata_opt[1] <= 028;
        0164:    rddata_opt[1] <= 127;
        0168:    rddata_opt[1] <= 012;
        0169:    rddata_opt[1] <= 024;
        0170:    rddata_opt[1] <= 048;
        0171:    rddata_opt[1] <= 127;
        0172:    rddata_opt[1] <= 012;
        0173:    rddata_opt[1] <= 031;
        0174:    rddata_opt[1] <= 062;
        0176:    rddata_opt[1] <= 051;
        0177:    rddata_opt[1] <= 062;
        0178:    rddata_opt[1] <= 012;
        0179:    rddata_opt[1] <= 107;
        0180:    rddata_opt[1] <= 099;
        0181:    rddata_opt[1] <= 051;
        0182:    rddata_opt[1] <= 030;
        0183:    rddata_opt[1] <= 048;
        0184:    rddata_opt[1] <= 048;
        0185:    rddata_opt[1] <= 051;
        0186:    rddata_opt[1] <= 024;
        0187:    rddata_opt[1] <= 107;
        0188:    rddata_opt[1] <= 051;
        0189:    rddata_opt[1] <= 051;
        0190:    rddata_opt[1] <= 102;
        0195:    rddata_opt[1] <= 028;
        0196:    rddata_opt[1] <= 031;
        0200:    rddata_opt[1] <= 012;
        0201:    rddata_opt[1] <= 012;
        0202:    rddata_opt[1] <= 048;
        0204:    rddata_opt[1] <= 012;
        0205:    rddata_opt[1] <= 048;
        0206:    rddata_opt[1] <= 024;
        0207:    rddata_opt[1] <= 126;
        0208:    rddata_opt[1] <= 063;
        0209:    rddata_opt[1] <= 038;
        0210:    rddata_opt[1] <= 012;
        0211:    rddata_opt[1] <= 099;
        0212:    rddata_opt[1] <= 115;
        0213:    rddata_opt[1] <= 051;
        0214:    rddata_opt[1] <= 012;
        0215:    rddata_opt[1] <= 048;
        0216:    rddata_opt[1] <= 062;
        0217:    rddata_opt[1] <= 063;
        0218:    rddata_opt[1] <= 024;
        0219:    rddata_opt[1] <= 107;
        0220:    rddata_opt[1] <= 051;
        0221:    rddata_opt[1] <= 051;
        0222:    rddata_opt[1] <= 102;
        0227:    rddata_opt[1] <= 054;
        0228:    rddata_opt[1] <= 007;
        0233:    rddata_opt[1] <= 006;
        0234:    rddata_opt[1] <= 024;
        0236:    rddata_opt[1] <= 012;
        0237:    rddata_opt[1] <= 048;
        0238:    rddata_opt[1] <= 024;
        0240:    rddata_opt[1] <= 051;
        0241:    rddata_opt[1] <= 006;
        0242:    rddata_opt[1] <= 012;
        0243:    rddata_opt[1] <= 099;
        0244:    rddata_opt[1] <= 123;
        0245:    rddata_opt[1] <= 051;
        0246:    rddata_opt[1] <= 012;
        0247:    rddata_opt[1] <= 048;
        0248:    rddata_opt[1] <= 051;
        0249:    rddata_opt[1] <= 003;
        0250:    rddata_opt[1] <= 024;
        0251:    rddata_opt[1] <= 107;
        0252:    rddata_opt[1] <= 051;
        0253:    rddata_opt[1] <= 051;
        0254:    rddata_opt[1] <= 102;
        0259:    rddata_opt[1] <= 099;
        0260:    rddata_opt[1] <= 003;
        0264:    rddata_opt[1] <= 012;
        0265:    rddata_opt[1] <= 051;
        0266:    rddata_opt[1] <= 012;
        0268:    rddata_opt[1] <= 012;
        0269:    rddata_opt[1] <= 051;
        0270:    rddata_opt[1] <= 012;
        0272:    rddata_opt[1] <= 051;
        0273:    rddata_opt[1] <= 070;
        0274:    rddata_opt[1] <= 012;
        0275:    rddata_opt[1] <= 099;
        0276:    rddata_opt[1] <= 062;
        0277:    rddata_opt[1] <= 051;
        0278:    rddata_opt[1] <= 012;
        0279:    rddata_opt[1] <= 048;
        0280:    rddata_opt[1] <= 051;
        0281:    rddata_opt[1] <= 051;
        0282:    rddata_opt[1] <= 024;
        0283:    rddata_opt[1] <= 107;
        0284:    rddata_opt[1] <= 051;
        0285:    rddata_opt[1] <= 051;
        0286:    rddata_opt[1] <= 060;
        0292:    rddata_opt[1] <= 001;
        0296:    rddata_opt[1] <= 012;
        0297:    rddata_opt[1] <= 049;
        0298:    rddata_opt[1] <= 006;
        0300:    rddata_opt[1] <= 063;
        0301:    rddata_opt[1] <= 030;
        0302:    rddata_opt[1] <= 014;
        0304:    rddata_opt[1] <= 051;
        0305:    rddata_opt[1] <= 127;
        0306:    rddata_opt[1] <= 030;
        0307:    rddata_opt[1] <= 099;
        0308:    rddata_opt[1] <= 048;
        0309:    rddata_opt[1] <= 030;
        0310:    rddata_opt[1] <= 030;
        0311:    rddata_opt[1] <= 060;
        0312:    rddata_opt[1] <= 110;
        0313:    rddata_opt[1] <= 030;
        0314:    rddata_opt[1] <= 126;
        0315:    rddata_opt[1] <= 099;
        0316:    rddata_opt[1] <= 062;
        0317:    rddata_opt[1] <= 110;
        0318:    rddata_opt[1] <= 048;
        0340:    rddata_opt[1] <= 120;
        0348:    rddata_opt[1] <= 048;
        0350:    rddata_opt[1] <= 024;
        0380:    rddata_opt[1] <= 120;
        0382:    rddata_opt[1] <= 015;
        default: rddata_opt[1] <= 000;
      endcase

      case ({char_line,char_addr[6:2]})
        0023:    rddata_opt[2] <= 008;
        0032:    rddata_opt[2] <= 126;
        0034:    rddata_opt[2] <= 028;
        0044:    rddata_opt[2] <= 030;
        0045:    rddata_opt[2] <= 028;
        0047:    rddata_opt[2] <= 006;
        0048:    rddata_opt[2] <= 063;
        0049:    rddata_opt[2] <= 127;
        0050:    rddata_opt[2] <= 120;
        0051:    rddata_opt[2] <= 099;
        0052:    rddata_opt[2] <= 063;
        0053:    rddata_opt[2] <= 051;
        0054:    rddata_opt[2] <= 127;
        0055:    rddata_opt[2] <= 028;
        0056:    rddata_opt[2] <= 007;
        0057:    rddata_opt[2] <= 028;
        0058:    rddata_opt[2] <= 048;
        0064:    rddata_opt[2] <= 195;
        0066:    rddata_opt[2] <= 034;
        0076:    rddata_opt[2] <= 051;
        0077:    rddata_opt[2] <= 006;
        0079:    rddata_opt[2] <= 012;
        0080:    rddata_opt[2] <= 102;
        0081:    rddata_opt[2] <= 102;
        0082:    rddata_opt[2] <= 048;
        0083:    rddata_opt[2] <= 099;
        0084:    rddata_opt[2] <= 102;
        0085:    rddata_opt[2] <= 051;
        0086:    rddata_opt[2] <= 115;
        0087:    rddata_opt[2] <= 054;
        0088:    rddata_opt[2] <= 006;
        0089:    rddata_opt[2] <= 054;
        0090:    rddata_opt[2] <= 048;
        0096:    rddata_opt[2] <= 129;
        0098:    rddata_opt[2] <= 093;
        0102:    rddata_opt[2] <= 012;
        0106:    rddata_opt[2] <= 102;
        0108:    rddata_opt[2] <= 051;
        0109:    rddata_opt[2] <= 003;
        0110:    rddata_opt[2] <= 028;
        0111:    rddata_opt[2] <= 024;
        0112:    rddata_opt[2] <= 102;
        0113:    rddata_opt[2] <= 070;
        0114:    rddata_opt[2] <= 048;
        0115:    rddata_opt[2] <= 103;
        0116:    rddata_opt[2] <= 102;
        0117:    rddata_opt[2] <= 051;
        0118:    rddata_opt[2] <= 025;
        0119:    rddata_opt[2] <= 099;
        0120:    rddata_opt[2] <= 006;
        0121:    rddata_opt[2] <= 006;
        0128:    rddata_opt[2] <= 165;
        0130:    rddata_opt[2] <= 069;
        0134:    rddata_opt[2] <= 006;
        0138:    rddata_opt[2] <= 060;
        0140:    rddata_opt[2] <= 048;
        0141:    rddata_opt[2] <= 003;
        0142:    rddata_opt[2] <= 028;
        0143:    rddata_opt[2] <= 048;
        0144:    rddata_opt[2] <= 102;
        0145:    rddata_opt[2] <= 038;
        0146:    rddata_opt[2] <= 048;
        0147:    rddata_opt[2] <= 111;
        0148:    rddata_opt[2] <= 102;
        0149:    rddata_opt[2] <= 051;
        0150:    rddata_opt[2] <= 024;
        0152:    rddata_opt[2] <= 062;
        0153:    rddata_opt[2] <= 006;
        0154:    rddata_opt[2] <= 060;
        0155:    rddata_opt[2] <= 031;
        0156:    rddata_opt[2] <= 055;
        0157:    rddata_opt[2] <= 051;
        0158:    rddata_opt[2] <= 063;
        0160:    rddata_opt[2] <= 129;
        0162:    rddata_opt[2] <= 069;
        0166:    rddata_opt[2] <= 127;
        0170:    rddata_opt[2] <= 255;
        0172:    rddata_opt[2] <= 024;
        0173:    rddata_opt[2] <= 031;
        0175:    rddata_opt[2] <= 096;
        0176:    rddata_opt[2] <= 062;
        0177:    rddata_opt[2] <= 062;
        0178:    rddata_opt[2] <= 048;
        0179:    rddata_opt[2] <= 127;
        0180:    rddata_opt[2] <= 062;
        0181:    rddata_opt[2] <= 051;
        0182:    rddata_opt[2] <= 012;
        0184:    rddata_opt[2] <= 102;
        0185:    rddata_opt[2] <= 031;
        0186:    rddata_opt[2] <= 048;
        0187:    rddata_opt[2] <= 051;
        0188:    rddata_opt[2] <= 118;
        0189:    rddata_opt[2] <= 051;
        0190:    rddata_opt[2] <= 049;
        0192:    rddata_opt[2] <= 189;
        0194:    rddata_opt[2] <= 069;
        0198:    rddata_opt[2] <= 006;
        0202:    rddata_opt[2] <= 060;
        0204:    rddata_opt[2] <= 012;
        0205:    rddata_opt[2] <= 051;
        0207:    rddata_opt[2] <= 048;
        0208:    rddata_opt[2] <= 102;
        0209:    rddata_opt[2] <= 038;
        0210:    rddata_opt[2] <= 051;
        0211:    rddata_opt[2] <= 123;
        0212:    rddata_opt[2] <= 054;
        0213:    rddata_opt[2] <= 051;
        0214:    rddata_opt[2] <= 006;
        0216:    rddata_opt[2] <= 102;
        0217:    rddata_opt[2] <= 006;
        0218:    rddata_opt[2] <= 048;
        0219:    rddata_opt[2] <= 051;
        0220:    rddata_opt[2] <= 110;
        0221:    rddata_opt[2] <= 051;
        0222:    rddata_opt[2] <= 024;
        0224:    rddata_opt[2] <= 153;
        0226:    rddata_opt[2] <= 093;
        0230:    rddata_opt[2] <= 012;
        0234:    rddata_opt[2] <= 102;
        0236:    rddata_opt[2] <= 006;
        0237:    rddata_opt[2] <= 051;
        0238:    rddata_opt[2] <= 028;
        0239:    rddata_opt[2] <= 024;
        0240:    rddata_opt[2] <= 102;
        0241:    rddata_opt[2] <= 006;
        0242:    rddata_opt[2] <= 051;
        0243:    rddata_opt[2] <= 115;
        0244:    rddata_opt[2] <= 102;
        0245:    rddata_opt[2] <= 051;
        0246:    rddata_opt[2] <= 070;
        0248:    rddata_opt[2] <= 102;
        0249:    rddata_opt[2] <= 006;
        0250:    rddata_opt[2] <= 048;
        0251:    rddata_opt[2] <= 051;
        0252:    rddata_opt[2] <= 006;
        0253:    rddata_opt[2] <= 051;
        0254:    rddata_opt[2] <= 006;
        0256:    rddata_opt[2] <= 195;
        0258:    rddata_opt[2] <= 034;
        0267:    rddata_opt[2] <= 028;
        0268:    rddata_opt[2] <= 051;
        0269:    rddata_opt[2] <= 051;
        0270:    rddata_opt[2] <= 028;
        0271:    rddata_opt[2] <= 012;
        0272:    rddata_opt[2] <= 102;
        0273:    rddata_opt[2] <= 006;
        0274:    rddata_opt[2] <= 051;
        0275:    rddata_opt[2] <= 099;
        0276:    rddata_opt[2] <= 102;
        0277:    rddata_opt[2] <= 030;
        0278:    rddata_opt[2] <= 099;
        0280:    rddata_opt[2] <= 102;
        0281:    rddata_opt[2] <= 006;
        0282:    rddata_opt[2] <= 048;
        0283:    rddata_opt[2] <= 051;
        0284:    rddata_opt[2] <= 006;
        0285:    rddata_opt[2] <= 030;
        0286:    rddata_opt[2] <= 035;
        0288:    rddata_opt[2] <= 126;
        0290:    rddata_opt[2] <= 028;
        0299:    rddata_opt[2] <= 028;
        0300:    rddata_opt[2] <= 063;
        0301:    rddata_opt[2] <= 030;
        0303:    rddata_opt[2] <= 006;
        0304:    rddata_opt[2] <= 063;
        0305:    rddata_opt[2] <= 015;
        0306:    rddata_opt[2] <= 030;
        0307:    rddata_opt[2] <= 099;
        0308:    rddata_opt[2] <= 103;
        0309:    rddata_opt[2] <= 012;
        0310:    rddata_opt[2] <= 127;
        0312:    rddata_opt[2] <= 059;
        0313:    rddata_opt[2] <= 015;
        0314:    rddata_opt[2] <= 051;
        0315:    rddata_opt[2] <= 051;
        0316:    rddata_opt[2] <= 015;
        0317:    rddata_opt[2] <= 012;
        0318:    rddata_opt[2] <= 063;
        0346:    rddata_opt[2] <= 051;
        0378:    rddata_opt[2] <= 030;
        default: rddata_opt[2] <= 000;
      endcase

      case ({char_line,char_addr[6:2]})
        0044:    rddata_opt[3] <= 030;
        0045:    rddata_opt[3] <= 127;
        0047:    rddata_opt[3] <= 030;
        0048:    rddata_opt[3] <= 060;
        0049:    rddata_opt[3] <= 060;
        0050:    rddata_opt[3] <= 103;
        0051:    rddata_opt[3] <= 028;
        0052:    rddata_opt[3] <= 030;
        0053:    rddata_opt[3] <= 099;
        0054:    rddata_opt[3] <= 060;
        0058:    rddata_opt[3] <= 007;
        0064:    rddata_opt[3] <= 034;
        0075:    rddata_opt[3] <= 064;
        0076:    rddata_opt[3] <= 051;
        0077:    rddata_opt[3] <= 099;
        0079:    rddata_opt[3] <= 051;
        0080:    rddata_opt[3] <= 102;
        0081:    rddata_opt[3] <= 102;
        0082:    rddata_opt[3] <= 102;
        0083:    rddata_opt[3] <= 054;
        0084:    rddata_opt[3] <= 051;
        0085:    rddata_opt[3] <= 099;
        0086:    rddata_opt[3] <= 012;
        0090:    rddata_opt[3] <= 006;
        0096:    rddata_opt[3] <= 119;
        0102:    rddata_opt[3] <= 024;
        0106:    rddata_opt[3] <= 024;
        0107:    rddata_opt[3] <= 096;
        0108:    rddata_opt[3] <= 048;
        0109:    rddata_opt[3] <= 099;
        0110:    rddata_opt[3] <= 028;
        0111:    rddata_opt[3] <= 048;
        0112:    rddata_opt[3] <= 099;
        0113:    rddata_opt[3] <= 099;
        0114:    rddata_opt[3] <= 054;
        0115:    rddata_opt[3] <= 099;
        0116:    rddata_opt[3] <= 051;
        0117:    rddata_opt[3] <= 099;
        0118:    rddata_opt[3] <= 012;
        0122:    rddata_opt[3] <= 006;
        0128:    rddata_opt[3] <= 127;
        0134:    rddata_opt[3] <= 048;
        0138:    rddata_opt[3] <= 024;
        0139:    rddata_opt[3] <= 048;
        0140:    rddata_opt[3] <= 048;
        0141:    rddata_opt[3] <= 096;
        0142:    rddata_opt[3] <= 028;
        0143:    rddata_opt[3] <= 024;
        0144:    rddata_opt[3] <= 003;
        0145:    rddata_opt[3] <= 003;
        0146:    rddata_opt[3] <= 054;
        0147:    rddata_opt[3] <= 099;
        0148:    rddata_opt[3] <= 003;
        0149:    rddata_opt[3] <= 099;
        0150:    rddata_opt[3] <= 012;
        0152:    rddata_opt[3] <= 030;
        0153:    rddata_opt[3] <= 110;
        0154:    rddata_opt[3] <= 102;
        0155:    rddata_opt[3] <= 030;
        0156:    rddata_opt[3] <= 030;
        0157:    rddata_opt[3] <= 099;
        0160:    rddata_opt[3] <= 127;
        0166:    rddata_opt[3] <= 127;
        0170:    rddata_opt[3] <= 126;
        0171:    rddata_opt[3] <= 024;
        0172:    rddata_opt[3] <= 028;
        0173:    rddata_opt[3] <= 048;
        0175:    rddata_opt[3] <= 012;
        0176:    rddata_opt[3] <= 003;
        0177:    rddata_opt[3] <= 003;
        0178:    rddata_opt[3] <= 030;
        0179:    rddata_opt[3] <= 099;
        0180:    rddata_opt[3] <= 014;
        0181:    rddata_opt[3] <= 107;
        0182:    rddata_opt[3] <= 012;
        0184:    rddata_opt[3] <= 051;
        0185:    rddata_opt[3] <= 051;
        0186:    rddata_opt[3] <= 054;
        0187:    rddata_opt[3] <= 051;
        0188:    rddata_opt[3] <= 051;
        0189:    rddata_opt[3] <= 099;
        0192:    rddata_opt[3] <= 127;
        0198:    rddata_opt[3] <= 048;
        0202:    rddata_opt[3] <= 024;
        0203:    rddata_opt[3] <= 012;
        0204:    rddata_opt[3] <= 048;
        0205:    rddata_opt[3] <= 024;
        0207:    rddata_opt[3] <= 012;
        0208:    rddata_opt[3] <= 003;
        0209:    rddata_opt[3] <= 115;
        0210:    rddata_opt[3] <= 054;
        0211:    rddata_opt[3] <= 099;
        0212:    rddata_opt[3] <= 024;
        0213:    rddata_opt[3] <= 107;
        0214:    rddata_opt[3] <= 012;
        0216:    rddata_opt[3] <= 003;
        0217:    rddata_opt[3] <= 051;
        0218:    rddata_opt[3] <= 030;
        0219:    rddata_opt[3] <= 051;
        0220:    rddata_opt[3] <= 006;
        0221:    rddata_opt[3] <= 107;
        0224:    rddata_opt[3] <= 062;
        0230:    rddata_opt[3] <= 024;
        0234:    rddata_opt[3] <= 024;
        0235:    rddata_opt[3] <= 006;
        0236:    rddata_opt[3] <= 048;
        0237:    rddata_opt[3] <= 012;
        0238:    rddata_opt[3] <= 028;
        0240:    rddata_opt[3] <= 099;
        0241:    rddata_opt[3] <= 099;
        0242:    rddata_opt[3] <= 054;
        0243:    rddata_opt[3] <= 099;
        0244:    rddata_opt[3] <= 051;
        0245:    rddata_opt[3] <= 054;
        0246:    rddata_opt[3] <= 012;
        0248:    rddata_opt[3] <= 003;
        0249:    rddata_opt[3] <= 051;
        0250:    rddata_opt[3] <= 054;
        0251:    rddata_opt[3] <= 051;
        0252:    rddata_opt[3] <= 024;
        0253:    rddata_opt[3] <= 107;
        0256:    rddata_opt[3] <= 028;
        0267:    rddata_opt[3] <= 003;
        0268:    rddata_opt[3] <= 051;
        0269:    rddata_opt[3] <= 012;
        0270:    rddata_opt[3] <= 028;
        0271:    rddata_opt[3] <= 012;
        0272:    rddata_opt[3] <= 102;
        0273:    rddata_opt[3] <= 102;
        0274:    rddata_opt[3] <= 102;
        0275:    rddata_opt[3] <= 054;
        0276:    rddata_opt[3] <= 051;
        0277:    rddata_opt[3] <= 054;
        0278:    rddata_opt[3] <= 012;
        0280:    rddata_opt[3] <= 051;
        0281:    rddata_opt[3] <= 062;
        0282:    rddata_opt[3] <= 102;
        0283:    rddata_opt[3] <= 051;
        0284:    rddata_opt[3] <= 051;
        0285:    rddata_opt[3] <= 054;
        0288:    rddata_opt[3] <= 008;
        0299:    rddata_opt[3] <= 001;
        0300:    rddata_opt[3] <= 030;
        0301:    rddata_opt[3] <= 012;
        0302:    rddata_opt[3] <= 024;
        0303:    rddata_opt[3] <= 012;
        0304:    rddata_opt[3] <= 060;
        0305:    rddata_opt[3] <= 124;
        0306:    rddata_opt[3] <= 103;
        0307:    rddata_opt[3] <= 028;
        0308:    rddata_opt[3] <= 030;
        0309:    rddata_opt[3] <= 054;
        0310:    rddata_opt[3] <= 060;
        0312:    rddata_opt[3] <= 030;
        0313:    rddata_opt[3] <= 048;
        0314:    rddata_opt[3] <= 103;
        0315:    rddata_opt[3] <= 030;
        0316:    rddata_opt[3] <= 030;
        0317:    rddata_opt[3] <= 054;
        0334:    rddata_opt[3] <= 012;
        0343:    rddata_opt[3] <= 255;
        0345:    rddata_opt[3] <= 051;
        0377:    rddata_opt[3] <= 030;
        default: rddata_opt[3] <= 000;
      endcase
    end
    if (rden_r)
      rddata <= rddata_opt[lsb_addr_r];
    end

endmodule
