/*********************************************************************************
 *
 * This file is part of the N64 RGB/YPbPr DAC project.
 *
 * Copyright (C) 2015-2023 by Peter Bartmann <borti4938@gmail.com>
 *
 * N64 RGB/YPbPr DAC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *********************************************************************************
 *
 * cfg_header/cfg_io_p.h
 *
 *  Created on: 17.01.2018
 *      Author: Peter Bartmann
 *
 ********************************************************************************/

#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"

#include "config.h"
#include "menu.h"
#include "vd_driver.h"


#ifndef CFG_HEADER_CFG_IO_P_H_
#define CFG_HEADER_CFG_IO_P_H_

extern char szText[VD_WIDTH];

extern const char *OffOn[], *Force5060[], *Resolutions[], *DeInterModes[], *InterpModes[],
                  *ScanlinesThickness[], *ScanlinesScaleProfile[], *ScanlinesCalcBase[],
                  *RstMasking[];


// scaler
cfg_b32word_t extcfg0_word =
  { .cfg_word_mask    = EXTCFG0_GETALL_MASK,
    .cfg_word_val     = 0x000000000,
    .cfg_ref_word_val = 0x000000000
  };

config_t vert_scale = {
    .cfg_word        = &extcfg0_word,
    .cfg_word_offset = CFG_VERTSCALE_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_VERTSCALE_MAX_VALUE,
        .getvalue_mask = CFG_VERTSCALE_GETMASK
    },
    .val2char_func = &val2txt_func
};

config_t hor_scale = {
    .cfg_word        = &extcfg0_word,
    .cfg_word_offset = CFG_HORSCALE_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_HORSCALE_MAX_VALUE,
        .getvalue_mask = CFG_HORSCALE_GETMASK
    },
    .val2char_func = &val2txt_func
};

config_t linex_force_5060 = {
    .cfg_word        = &extcfg0_word,
    .cfg_word_offset = CFG_FORCE_5060_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_FORCE5060_MAX_VALUE,
        .getvalue_mask = CFG_FORCE_5060_GETMASK
    },
    .value_string = (const char **) &Force5060
};

config_t low_latency_mode = {
    .cfg_word        = &extcfg0_word,
    .cfg_word_offset = CFG_LOWLATENCYMODE_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_LOWLATENCYMODE_SETMASK,
        .clrflag_mask = CFG_LOWLATENCYMODE_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t vga_for_480p = {
    .cfg_word        = &extcfg0_word,
    .cfg_word_offset = CFG_VGAFOR480P_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_VGAFOR480P_SETMASK,
        .clrflag_mask = CFG_VGAFOR480P_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t linex_resolution = {
    .cfg_word        = &extcfg0_word,
    .cfg_word_offset = CFG_RESOLUTION_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_RESOLUTION_MAX_VALUE,
        .getvalue_mask = CFG_RESOLUTION_GETMASK
    },
//    .value_string = &Resolutions
};

// osd, igr and vi-processing
cfg_b32word_t extcfg1_word =
  { .cfg_word_mask    = EXTCFG1_GETALL_MASK,
    .cfg_word_val     = 0x00000000,
    .cfg_ref_word_val = 0x00000000
  };

config_t show_logo = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_SHOWLOGO_OFFSET,
    .cfg_type        = FLAG,
    .flag_masks      = {
        .setflag_mask = CFG_SHOWLOGO_SETMASK,
        .clrflag_mask = CFG_SHOWLOGO_CLRMASK
    }
};

config_t show_osd = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_SHOWOSD_OFFSET,
    .cfg_type        = FLAG,
    .flag_masks      = {
        .setflag_mask = CFG_SHOWOSD_SETMASK,
        .clrflag_mask = CFG_SHOWOSD_CLRMASK
    }
};

config_t mute_osd_tmp = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_MUTEOSDTMP_OFFSET,
    .cfg_type        = FLAG,
    .flag_masks      = {
        .setflag_mask = CFG_MUTEOSDTMP_SETMASK,
        .clrflag_mask = CFG_MUTEOSDTMP_CLRMASK
    }
};

config_t igr_reset = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_IGRRST_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_IGRRST_SETMASK,
        .clrflag_mask = CFG_IGRRST_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t rst_masking = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_RSTMASKS_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_RSTMASKS_MAX_VALUE,
        .getvalue_mask = CFG_RSTMASKS_GETMASK
    },
    .value_string = (const char **) &RstMasking
};

config_t gamma_lut = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_GAMMA_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_GAMMA_MAX_VALUE,
        .getvalue_mask = CFG_GAMMA_GETMASK
    },
    .val2char_func = &gamma2txt_func
};

config_t deblur_mode = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_DEBLUR_MODE_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_DEBLUR_MODE_SETMASK,
        .clrflag_mask = CFG_DEBLUR_MODE_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t mode16bit = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_16BITMODE_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_16BITMODE_SETMASK,
        .clrflag_mask = CFG_16BITMODE_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t vert_shift = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_VERTSHIFT_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_VERTSHIFT_MAX_VALUE,
        .getvalue_mask = CFG_VERTSHIFT_GETMASK
    },
    .val2char_func = &val2txt_5b_binaryoffset_func
};

config_t hor_shift = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_HORSHIFT_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_HORSHIFT_MAX_VALUE,
        .getvalue_mask = CFG_HORSHIFT_GETMASK
    },
    .val2char_func = &val2txt_5b_binaryoffset_func
};

config_t deinterlace_mode = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_DEINTER_MODE_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_DEINTER_MODE_MAX_VALUE,
        .getvalue_mask = CFG_DEINTER_MODE_GETMASK
    },
    .value_string = (const char **) &DeInterModes
};

config_t interpolation_mode_vert = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_V_INTERP_MODE_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_INTERP_MODE_MAX_VALUE,
        .getvalue_mask = CFG_V_INTERP_MODE_GETMASK
    },
    .value_string = (const char **) &InterpModes
};

config_t interpolation_mode_hori = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_H_INTERP_MODE_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_INTERP_MODE_MAX_VALUE,
        .getvalue_mask = CFG_H_INTERP_MODE_GETMASK
    },
    .value_string = (const char **) &InterpModes
};

config_t pal_boxed_mode = {
    .cfg_word        = &extcfg1_word,
    .cfg_word_offset = CFG_PAL_BOXED_MODE_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_PAL_BOXED_MODE_SETMASK,
        .clrflag_mask = CFG_PAL_BOXED_MODE_CLRMASK
    },
    .val2char_func = &flag2set_func
};

// scanlines
cfg_b32word_t extcfg2_word =
  { .cfg_word_mask    = EXTCFG2_GETALL_MASK,
    .cfg_word_val     = 0x00000000,
    .cfg_ref_word_val = 0x00000000
  };

config_t sl_thickness_vert = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_VSL_THICKNESS_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_SL_THICKNESS_MAX_VALUE,
        .getvalue_mask = CFG_VSL_THICKNESS_GETMASK
    },
    .value_string = (const char **) &ScanlinesThickness
};

config_t sl_profile_vert = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_VSL_PROFILE_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_SL_PROFILE_MAX_VALUE,
        .getvalue_mask = CFG_VSL_PROFILE_GETMASK
    },
    .value_string = (const char **) &ScanlinesScaleProfile
};

config_t slhyb_str_vert = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_VSLHYBDEP_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_SLHYBDEP_MAX_VALUE,
        .getvalue_mask = CFG_VSLHYBDEP_GETMASK
    },
    .val2char_func = &scanline_hybrstr2txt_func
};

config_t sl_str_vert = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_VSLSTR_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_SLSTR_MAX_VALUE,
        .getvalue_mask = CFG_VSLSTR_GETMASK
    },
    .val2char_func = &scanline_str2txt_func
};

config_t sl_thickness_hori = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_HSL_THICKNESS_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_SL_THICKNESS_MAX_VALUE,
        .getvalue_mask = CFG_HSL_THICKNESS_GETMASK
    },
    .value_string = (const char **) &ScanlinesThickness
};

config_t sl_profile_hori = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_HSL_PROFILE_OFFSET,
    .cfg_type        = TXTVALUE,
    .value_details   = {
        .max_value     = CFG_SL_PROFILE_MAX_VALUE,
        .getvalue_mask = CFG_HSL_PROFILE_GETMASK
    },
    .value_string = (const char **) &ScanlinesScaleProfile
};

config_t slhyb_str_hori = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_HSLHYBDEP_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_SLHYBDEP_MAX_VALUE,
        .getvalue_mask = CFG_HSLHYBDEP_GETMASK
    },
    .val2char_func = &scanline_hybrstr2txt_func
};

config_t sl_str_hori = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_HSLSTR_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_SLSTR_MAX_VALUE,
        .getvalue_mask = CFG_HSLSTR_GETMASK
    },
    .val2char_func = &scanline_str2txt_func
};

config_t sl_en_vert = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_VSL_EN_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_VSL_EN_SETMASK,
        .clrflag_mask = CFG_VSL_EN_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t sl_en_hori = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_HSL_EN_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_HSL_EN_SETMASK,
        .clrflag_mask = CFG_HSL_EN_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t sl_link_h2v = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_H2V_SL_LINK_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_H2V_SL_LINK_SETMASK,
        .clrflag_mask = CFG_H2V_SL_LINK_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t sl_calc_base = {
    .cfg_word        = &extcfg2_word,
    .cfg_word_offset = CFG_SL_CALC_BASE_OFFSET,
    .cfg_type        = FLAG,
    .flag_masks      = {
        .setflag_mask = CFG_SL_CALC_BASE_SETMASK,
        .clrflag_mask = CFG_SL_CALC_BASE_CLRMASK
    },
    .value_string = (const char **) &ScanlinesCalcBase
};

// audio
cfg_b32word_t extcfg3_word =
  { .cfg_word_mask    = EXTCFG3_GETALL_MASK,
    .cfg_word_val     = 0x00000000,
    .cfg_ref_word_val = 0x00000000
  };

config_t audio_fliter_bypass = {
    .cfg_word        = &extcfg3_word,
    .cfg_word_offset = CFG_AUDIO_FILTER_BYPASS_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_AUDIO_FILTER_BYPASS_SETMASK,
        .clrflag_mask = CFG_AUDIO_FILTER_BYPASS_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t audio_amp = {
    .cfg_word        = &extcfg3_word,
    .cfg_word_offset = CFG_AUDIO_AMP_OFFSET,
    .cfg_type        = NUMVALUE,
    .value_details   = {
        .max_value     = CFG_AUDIO_AMP_MAX_VALUE,
        .getvalue_mask = CFG_AUDIO_AMP_GETMASK
    },
    .val2char_func = &audioamp2txt_func
};

config_t audio_swap_lr = {
    .cfg_word        = &extcfg3_word,
    .cfg_word_offset = CFG_AUDIO_SWAP_LR_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_AUDIO_SWAP_LR_SETMASK,
        .clrflag_mask = CFG_AUDIO_SWAP_LR_CLRMASK
    },
    .val2char_func = &flag2set_func
};

config_t audio_spdif_en = {
    .cfg_word        = &extcfg3_word,
    .cfg_word_offset = CFG_AUDIO_SPDIF_EN_OFFSET,
    .cfg_type        = FLAGTXT,
    .flag_masks      = {
        .setflag_mask = CFG_AUDIO_SPDIF_EN_SETMASK,
        .clrflag_mask = CFG_AUDIO_SPDIF_EN_CLRMASK
    },
    .val2char_func = &flag2set_func
};



#endif /* CFG_HEADER_CFG_IO_P_H_ */
