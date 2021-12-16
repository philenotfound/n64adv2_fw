
task setOSDConfig;
  input [`VID_CFG_W-1:0] videomode;
  
  output [2:0] osd_vscale;
  output [1:0] osd_hscale;
  output [10:0] osd_voffset;
  output [11:0] osd_hoffset;
  
  begin
    case (cfg_videomode)
      `USE_VGAp60: begin
          cfg_osd_vscale <= 3'b001;
          cfg_osd_hscale <= 2'b00;
          cfg_osd_voffset <=  59;   // (`VSYNCLEN_VGA + `VBACKPORCH_VGA + (`VACTIVE_VGA - 2*`OSD_WINDOW_VACTIVE)/2)/2
                                    // = (2 + 33 +(480 - 2*156)/2)/2 = 119/2 = 59,5
          cfg_osd_hoffset <=  248;  // `HSYNCLEN_VGA + `HBACKPORCH_VGA + (`HACTIVE_VGA - `OSD_WINDOW_HACTIVE)/2
                                    // = 96 + 48 + (640-431)/2 = 248,5
         end
      `USE_720p60: begin
          cfg_osd_vscale <= 3'b010;
          cfg_osd_hscale <= 2'b01;
          cfg_osd_voffset <= 50;  // (`VSYNCLEN_720p60 + `VBACKPORCH_720p60 + (`VACTIVE_720P60 - 3*`OSD_WINDOW_VACTIVE)/2)/3;
                                  // = (5 + 20 + (720 - 3*156)/2)/3 = 151/3 = 50,3
          cfg_osd_hoffset <= 234; // (`HSYNCLEN_720p60 + `HBACKPORCH_720p60 + (`HACTIVE_720P60 - 2*`OSD_WINDOW_HACTIVE)/2)/2
                                  // = (40 + 220 + (1280 - 2*431)/2)/2 = 469/2 = 234,5
         end
      `USE_960p60: begin
          cfg_osd_vscale <= 3'b011;
          cfg_osd_hscale <= 2'b01;
          cfg_osd_voffset <= 48;  // (`VSYNCLEN_960p60 + `VBACKPORCH_960p60 + (`VACTIVE_960P60 - 5*`OSD_WINDOW_VACTIVE)/2)/4;
                                  // = (4 + 21 + (960 - 4*156)/2)/4 = 193/4 = 48,25
          cfg_osd_hoffset <= 160; // (`HSYNCLEN_960p60 + `HBACKPORCH_960p60 + (`HACTIVE_960P60 - 2*`OSD_WINDOW_HACTIVE)/2)/2
                                  // = (32 + 80 + (1280 - 2*431)/2)/2 = 321/2 = 160,5
         end
      `USE_1080p60: begin
          cfg_osd_vscale <= 3'b100;
          cfg_osd_hscale <= 2'b10;
          cfg_osd_voffset <= 38;  // (`VSYNCLEN_1080p60 + `VBACKPORCH_1080p60 + (`VACTIVE_1080P60 - 5*`OSD_WINDOW_VACTIVE)/2)/5
                                  // = (5 + 36 + (1080 - 5*156)/2)/5 = 191/5 = 38,2
          cfg_osd_hoffset <= 168; // (`HSYNCLEN_1080p60 + `HBACKPORCH_1080p60 + (`HACTIVE_1080P60 - 3*`OSD_WINDOW_HACTIVE)/2)/3
                                  // = (44 + 148 + (1920 - 3*431)/2)/3 = 505,5/3 = 168,5
         end
      `USE_1200p60: begin
          cfg_osd_vscale <= 3'b100;
          cfg_osd_hscale <= 2'b10;
          cfg_osd_voffset <= 48;  // (`VSYNCLEN_1200p60 + `VBACKPORCH_1200p60 + (`VACTIVE_1200P60 - 5*`OSD_WINDOW_VACTIVE)/2)/5
                                  // = (4 + 28 + (1200 - 5*156)/2)/5 = 242/5 = 48,4
          cfg_osd_hoffset <= 88;  // (`HSYNCLEN_1200p60 + `HBACKPORCH_1200p60 + (`HACTIVE_1200P60 - 3*`OSD_WINDOW_HACTIVE)/2)/3
                                  // = (32 + 80 + (1600 - 3*431)/2)/3 = 265,5/3 = 88,5
         end
      `USE_720p50: begin
          cfg_osd_vscale <= 3'b010;
          cfg_osd_hscale <= 2'b01;
          cfg_osd_voffset <= 50;  // (`VSYNCLEN_720p50 + `VBACKPORCH_720p50 + (`VACTIVE_720P50 - 3*`OSD_WINDOW_VACTIVE)/2)/3;
                                  // = (5 + 20 + (720 - 3*156)/2)/3 = 151/3 = 50,3
          cfg_osd_hoffset <= 234; // (`HSYNCLEN_720p50 + `HBACKPORCH_720p50 + (`HACTIVE_720P50 - 2*`OSD_WINDOW_HACTIVE)/2)/2
                                  // = (40 + 220 + (1280 - 2*431)/2)/2 = 469/2 = 234,5
         end
      `USE_960p50: begin
          cfg_osd_vscale <= 3'b011;
          cfg_osd_hscale <= 2'b01;
          cfg_osd_voffset <= 48;  // (`VSYNCLEN_960p50 + `VBACKPORCH_960p50 + (`VACTIVE_960P50 - 2*`OSD_WINDOW_VACTIVE)/2)/2;
                                  // = (4 + 21 + (960 - 4*156)/2)/4 = 193/4 = 48,25
          cfg_osd_hoffset <= 160; // (`HSYNCLEN_960p50 + `HBACKPORCH_960p50 + (`HACTIVE_960P50 - 2*`OSD_WINDOW_HACTIVE)/2)/2
                                  // = (32 + 80 + (1280 - 2*431)/2)/2 = 321/2 = 160,5
         end
      `USE_1080p50: begin
          cfg_osd_vscale <= 3'b100;
          cfg_osd_hscale <= 2'b10;
          cfg_osd_voffset <= 38;  // (`VSYNCLEN_1080p50 + `VBACKPORCH_1080p50 + (`VACTIVE_1080P50 - 5*`OSD_WINDOW_VACTIVE)/2)/5
                                  // = (5 + 36 + (1080 - 5*156)/2)/5 = 269/4 = 38,2
          cfg_osd_hoffset <= 168; // (`HSYNCLEN_1080p50 + `HBACKPORCH_1080p50 + (`HACTIVE_1080P50 - 3*`OSD_WINDOW_HACTIVE)/2)/3
                                  // = (44 + 148 + (1920 - 3*431)/2)/3 = 505,5/3 = 168,5
         end
      `USE_1200p50: begin
          cfg_osd_vscale <= 3'b100;
          cfg_osd_hscale <= 2'b10;
          cfg_osd_voffset <= 48;  // (`VSYNCLEN_1200p50 + `VBACKPORCH_1200p50 + (`VACTIVE_1200P50 - 5*`OSD_WINDOW_VACTIVE)/2)/5
                                  // = (4 + 28 + (1200 - 5*156)/2)/5 = 242/5 = 48,4
          cfg_osd_hoffset <= 88;  // (`HSYNCLEN_1200p50 + `HBACKPORCH_1200p50 + (`HACTIVE_1200P50 - 3*`OSD_WINDOW_HACTIVE)/2)/3
                                  // = (32 + 80 + (1600 - 3*431)/2)/3 = 265,5/3 = 88,5
         end
      default: begin
          cfg_osd_vscale <= 3'b001;
          cfg_osd_hscale <= 2'b00;
          if (cfg_videomode[`VID_CFG_50HZ_BIT]) begin
            cfg_osd_voffset <= 88;  // (`VSYNCLEN_576p50 + `VBACKPORCH_576p50 + (`VACTIVE_576p50 - 2*`OSD_WINDOW_VACTIVE)/2)/2
                                    // = (5 + 39 + (576 - 2*156)/2)/2 = 176/2 = 88
            cfg_osd_hoffset <= 276; // `HSYNCLEN_576p50 + `HBACKPORCH_576p50 + (`HACTIVE_576p50 - `OSD_WINDOW_HACTIVE)/2
                                    // = 64 + 68 + (720 - 431)/2 = 276,5
          end else begin
            cfg_osd_voffset <= 60;  // (`VSYNCLEN_480p60 + `VBACKPORCH_480p60 + (`VACTIVE_480p60 - 2*`OSD_WINDOW_VACTIVE)/2)/2
                                    // = (6 + 30 + (480 - 2*156)/2)/2 = 120/2 = 60
            cfg_osd_hoffset <= 266; // `HSYNCLEN_480p60 + `HBACKPORCH_480p60 + (`HACTIVE_480p60 - `OSD_WINDOW_HACTIVE)/2
                                    // = 62 + 60 + (720 - 431)/2 = 266,5
          end
        end
    endcase
  end
endtask
