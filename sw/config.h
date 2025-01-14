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
 * config.h
 *
 *  Created on: 11.01.2018
 *      Author: Peter Bartmann
 *
 ********************************************************************************/

#include <string.h>
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"


#ifndef CONFIG_H_
#define CONFIG_H_

typedef enum {
  INTCFG0 = 0,
  EXTCFG0,
  EXTCFG1,
  EXTCFG2,
  EXTCFG3
} cfg_word_type_t;

#define NUM_CFG_B32WORDS    5

typedef enum {
  NTSC = 0,
  PAL
} vmode_t;
#define LINEX_TYPES 2

typedef enum {
  PROGRESSIVE = 0,
  INTERLACED
} scanmode_t;

typedef enum {
  PPU_NTSC = 0,
  PPU_PAL,
  PPU_REGION_CURRENT
} cfg_region_sel_type_t;
#define NUM_REGION_MODES  PPU_REGION_CURRENT

typedef enum {
  NTSC_PROGRESSIVE = 0,
  NTSC_INTERLACED,
  PAL_PROGRESSIVE,
  PAL_INTERLACED,
  PPU_TIMING_CURRENT
} cfg_timing_model_sel_type_t;
#define NUM_TIMING_MODES  PPU_TIMING_CURRENT

typedef enum {
  NTSC_TO_240 = 0,
  NTSC_TO_480,
  NTSC_TO_720,
  NTSC_TO_960,
  NTSC_TO_1080,
  NTSC_TO_1200,
  NTSC_TO_1440,
  NTSC_TO_1440W,
  PAL_TO_288,
  PAL_TO_576,
  PAL_TO_720,
  PAL_TO_960,
  PAL_TO_1080,
  PAL_TO_1200,
  PAL_TO_1440,
  PAL_TO_1440W,
  PPU_SCALING_CURRENT
} cfg_scaler_in2out_sel_type_t;
#define NTSC_LAST_SCALING_MODE  NTSC_TO_1440W
#define NUM_SCALING_MODES       PPU_SCALING_CURRENT

typedef enum {
  PASSTHROUGH = 0,
  LineX2,
  LineX3,
  LineX4,
  LineX4p5,
  LineX5,
  LineX6,
  LineX6W
} linex_cnt;

typedef enum {
  FB_1080P = 0,
  FB_240P,
  FB_480P
} fallback_vmodes_t;

typedef enum {
  PAL_PAT0 = 0,
  PAL_PAT1
} cfg_pal_pattern_t;


typedef enum {
  OFF = 0,
  ON
} cfg_offon_t;

typedef enum {
  FALSE = 0,
  TRUE
} bool_t;
typedef bool_t boolean_t;

typedef struct {
  const alt_u32 cfg_word_mask;
  alt_u32       cfg_word_val;
  alt_u32       cfg_ref_word_val;
} cfg_b32word_t;

typedef struct {
	cfg_b32word_t* cfg_word_def[NUM_CFG_B32WORDS];
} configuration_t;

typedef enum {
  FLAG,
  FLAGTXT,
  TXTVALUE,
  NUMVALUE
} config_type_t;

typedef struct {
  const alt_u32 setflag_mask;
  const alt_u32 clrflag_mask;
} config_flag_t;

typedef struct {
  const alt_u32 getvalue_mask;
  const alt_u16 max_value;
} config_value_t;

typedef void (*val2char_func_call)(alt_u16);

typedef struct {
  cfg_b32word_t       *cfg_word;
  union {
    alt_u8              cfg_word_offset;
    alt_u8              cfg_value;
  };
  const config_type_t cfg_type;
  union {
    const config_flag_t  flag_masks;
    const config_value_t value_details;
  };
  union {
    const char*        *value_string;
    val2char_func_call val2char_func;
  };
} config_t;

typedef struct {
  alt_u32 config_val;
  alt_u32 config_ref_val;
} config_tray_t;

typedef struct {
  alt_u16 config_val;
  alt_u16 config_ref_val;
} config_tray_u16_t;

typedef struct {
  alt_u8 config_val;
  alt_u8 config_ref_val;
} config_tray_u8_t;

#define CFG_VERSION_INVALID   100
#define CFG_FLASH_NOT_USED    101
#define CFG_FLASH_SAVE_ABORT  102
#define CFG_FLASH_LOAD_ABORT  CFG_FLASH_SAVE_ABORT
#define CFG_N64DEF_LOAD_ABORT CFG_FLASH_SAVE_ABORT
#define CFG_DEF_LOAD_ABORT    CFG_FLASH_SAVE_ABORT
#define CFG_RESYNC_ABORT      CFG_FLASH_SAVE_ABORT
#define CFG_CFG_COPY_ABORT    CFG_FLASH_SAVE_ABORT

#define PREDEFINED_SCALE_STEPS  21

// the overall masks
#define INTCFG0_GETALL_MASK   0x00002FFF
#define EXTCFG0_GETALL_MASK   0xFFFFFE7F
#define EXTCFG1_GETALL_MASK   0xFDFFFFB7
#define EXTCFG2_GETALL_MASK   0x3FFFFFFF
#define EXTCFG3_GETALL_MASK   0x000000FF

// internal cfg set 0
#define CFG_LEDSWAP_OFFSET                 13
#define CFG_COLORSPACE_OFFSET              10
#define CFG_LIMITED_COLORSPACE_OFFSET      9
#define CFG_LINK_HV_SCALE_OFFSET           7
#define CFG_DEBLUR_PC_DEFAULT_OFFSET       6
#define CFG_MODE16BIT_PC_DEFAULT_OFFSET    5
#define CFG_DEBLUR_IGR_OFFSET              4
#define CFG_MODE16BIT_IGR_OFFSET           3
#define CFG_FALLBACK_OFFSET                1
#define CFG_AUTOSAVE_OFFSET                0

#define CFG_LEDSWAP_GETMASK                 (1<<CFG_LEDSWAP_OFFSET)
  #define CFG_LEDSWAP_SETMASK                 (1<<CFG_LEDSWAP_OFFSET)
  #define CFG_LEDSWAP_CLRMASK                 (INTCFG0_GETALL_MASK & ~CFG_LEDSWAP_GETMASK)
#define CFG_COLORSPACE_GETMASK              (3<<CFG_COLORSPACE_OFFSET)
  #define CFG_COLORSPACE_RSTMASK              (INTCFG0_GETALL_MASK & ~CFG_COLORSPACE_GETMASK)
  #define CFG_COLORSPACE_CLRMASK              (INTCFG0_GETALL_MASK & ~CFG_COLORSPACE_GETMASK)
#define CFG_LIMITED_COLORSPACE_GETMASK      (1<<CFG_LIMITED_COLORSPACE_OFFSET)
  #define CFG_LIMITED_COLORSPACE_SETMASK      (1<<CFG_LIMITED_COLORSPACE_OFFSET)
  #define CFG_LIMITED_COLORSPACE_CLRMASK      (INTCFG0_GETALL_MASK & ~CFG_LIMITED_COLORSPACE_SETMASK)
#define CFG_LINK_HV_SCALE_GETMASK           (3<<CFG_LINK_HV_SCALE_OFFSET)
  #define CFG_LINK_HV_SCALE_RSTMASK           (INTCFG0_GETALL_MASK & ~CFG_LINK_HV_SCALE_GETMASK)
  #define CFG_LINK_HV_SCALE_CLRMASK           (INTCFG0_GETALL_MASK & ~CFG_LINK_HV_SCALE_GETMASK)
#define CFG_DEBLUR_PC_DEFAULT_GETMASK       (1<<CFG_DEBLUR_PC_DEFAULT_OFFSET)
  #define CFG_DEBLUR_PC_DEFAULT_SETMASK       (1<<CFG_DEBLUR_PC_DEFAULT_OFFSET)
  #define CFG_DEBLUR_PC_DEFAULT_CLRMASK       (INTCFG0_GETALL_MASK & ~CFG_DEBLUR_PC_DEFAULT_SETMASK)
#define CFG_MODE16BIT_PC_DEFAULT_GETMASK    (1<<CFG_MODE16BIT_PC_DEFAULT_OFFSET)
  #define CFG_MODE16BIT_PC_DEFAULT_SETMASK    (1<<CFG_MODE16BIT_PC_DEFAULT_OFFSET)
  #define CFG_MODE16BIT_PC_DEFAULT_CLRMASK    (INTCFG0_GETALL_MASK & ~CFG_MODE16BIT_PC_DEFAULT_SETMASK)
#define CFG_DEBLUR_IGR_GETMASK              (1<<CFG_DEBLUR_IGR_OFFSET)
  #define CFG_DEBLUR_IGR_SETMASK              (1<<CFG_DEBLUR_IGR_OFFSET)
  #define CFG_DEBLUR_IGR_CLRMASK              (INTCFG0_GETALL_MASK & ~CFG_DEBLUR_IGR_SETMASK)
#define CFG_MODE16BIT_IGR_GETMASK           (1<<CFG_MODE16BIT_IGR_OFFSET)
  #define CFG_MODE16BIT_IGR_SETMASK           (1<<CFG_MODE16BIT_IGR_OFFSET)
  #define CFG_MODE16BIT_IGR_CLRMASK           (INTCFG0_GETALL_MASK & ~CFG_MODE16BIT_IGR_SETMASK)
#define CFG_FALLBACK_GETMASK                (3<<CFG_FALLBACK_OFFSET)
  #define CFG_FALLBACK_RSTMASK                (INTCFG0_GETALL_MASK & ~CFG_FALBACK_SETMASK)
  #define CFG_FALLBACK_CLRMASK                (INTCFG0_GETALL_MASK & ~CFG_FALBACK_SETMASK)
#define CFG_AUTOSAVE_GETMASK                (1<<CFG_AUTOSAVE_OFFSET)
  #define CFG_AUTOSAVE_SETMASK                (1<<CFG_AUTOSAVE_OFFSET)
  #define CFG_AUTOSAVE_CLRMASK                (INTCFG0_GETALL_MASK & ~CFG_AUTOSAVE_SETMASK)


// external cfg set 0
#define EXTCFG0_OUT_BASE  CFG_SET0_OUT_BASE

#define CFG_VERTSCALE_OFFSET        21
#define CFG_HORSCALE_OFFSET          9
#define CFG_FORCE_5060_OFFSET        5
  #define CFG_FORCE_5060MSB_OFFSET     6
  #define CFG_FORCE_5060LSB_OFFSET     5
#define CFG_LOWLATENCYMODE_OFFSET    4
#define CFG_VGAFOR480P_OFFSET        3
#define CFG_RESOLUTION_OFFSET        0
  #define CFG_RESOLUTIONMSB_OFFSET     2
  #define CFG_RESOLUTIONLSB_OFFSET     0

#define CFG_VERTSCALE_GETMASK         (0x7FF<<CFG_VERTSCALE_OFFSET)
  #define CFG_VERTSCALE_RSTMASK         (EXTCFG0_GETALL_MASK & ~CFG_VERTSCALE_GETMASK)
  #define CFG_VERTSCALE_CLRMASK         (EXTCFG0_GETALL_MASK & ~CFG_VERTSCALE_GETMASK)
#define CFG_HORSCALE_GETMASK          (0xFFF<<CFG_HORSCALE_OFFSET)
  #define CFG_HORSCALE_RSTMASK          (EXTCFG0_GETALL_MASK & ~CFG_HORSCALE_GETMASK)
  #define CFG_HORSCALE_CLRMASK          (EXTCFG0_GETALL_MASK & ~CFG_HORSCALE_GETMASK)
#define CFG_FORCE_5060_GETMASK        (3<<CFG_FORCE_5060_OFFSET)
  #define CFG_FORCE_50_SETMASK          (2<<CFG_FORCE_5060_OFFSET)
  #define CFG_FORCE_60_SETMASK          (1<<CFG_FORCE_5060_OFFSET)
  #define CFG_FORCE_AUTO_SETMASK        (0<<CFG_FORCE_5060_OFFSET)
  #define CFG_FORCE_5060_RSTMASK        (EXTCFG0_GETALL_MASK & ~CFG_FORCE_5060_GETMASK)
#define CFG_LOWLATENCYMODE_GETMASK    (1<<CFG_LOWLATENCYMODE_OFFSET)
  #define CFG_LOWLATENCYMODE_SETMASK    (1<<CFG_LOWLATENCYMODE_OFFSET)
  #define CFG_LOWLATENCYMODE_CLRMASK    (EXTCFG0_GETALL_MASK & ~CFG_LOWLATENCYMODE_GETMASK)
#define CFG_VGAFOR480P_GETMASK        (3<<CFG_VGAFOR480P_OFFSET)
  #define CFG_VGAFOR480P_SETMASK        (1<<CFG_VGAFOR480P_OFFSET)
  #define CFG_VGAFOR480P_CLRMASK        (EXTCFG0_GETALL_MASK & ~CFG_VGAFOR480P_GETMASK)
#define CFG_RESOLUTION_GETMASK        (0x7<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_1440W_SETMASK  (LineX6W<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_1440_SETMASK   (LineX6<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_1200_SETMASK   (LineX5<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_1080_SETMASK   (LineX4p5<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_960_SETMASK    (LineX4<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_720_SETMASK    (LineX3<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_480_SETMASK    (LineX2<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_240_SETMASK    (PASSTHROUGH<<CFG_RESOLUTION_OFFSET)
  #define CFG_RESOLUTION_RSTMASK        (EXTCFG0_GETALL_MASK & ~CFG_RESOLUTION_GETMASK)

// external cfg set 1
#define EXTCFG1_OUT_BASE  CFG_SET1_OUT_BASE

#define CFG_SHOWLOGO_OFFSET       31
#define CFG_SHOWOSD_OFFSET        30
#define CFG_MUTEOSDTMP_OFFSET     29
#define CFG_IGRRST_OFFSET         28
#define CFG_RSTMASKS_OFFSET       26
#define CFG_GAMMA_OFFSET          21
#define CFG_DEBLUR_MODE_OFFSET    20
#define CFG_16BITMODE_OFFSET      19
#define CFG_VERTSHIFT_OFFSET      14
#define CFG_HORSHIFT_OFFSET        9
#define CFG_DEINTER_MODE_OFFSET    7
#define CFG_V_INTERP_MODE_OFFSET   4
#define CFG_H_INTERP_MODE_OFFSET   1
#define CFG_PAL_BOXED_MODE_OFFSET  0

#define CFG_SHOWLOGO_GETMASK        (1<<CFG_SHOWLOGO_OFFSET)
  #define CFG_SHOWLOGO_SETMASK        (1<<CFG_SHOWLOGO_OFFSET)
  #define CFG_SHOWLOGO_CLRMASK        (EXTCFG1_GETALL_MASK & ~CFG_SHOWLOGO_SETMASK)
#define CFG_SHOWOSD_GETMASK         (1<<CFG_SHOWOSD_OFFSET)
  #define CFG_SHOWOSD_SETMASK         (1<<CFG_SHOWOSD_OFFSET)
  #define CFG_SHOWOSD_CLRMASK         (EXTCFG1_GETALL_MASK & ~CFG_SHOWOSD_SETMASK)
#define CFG_MUTEOSDTMP_GETMASK      (1<<CFG_MUTEOSDTMP_OFFSET)
  #define CFG_MUTEOSDTMP_SETMASK      (1<<CFG_MUTEOSDTMP_OFFSET)
  #define CFG_MUTEOSDTMP_CLRMASK      (EXTCFG1_GETALL_MASK & ~CFG_MUTEOSDTMP_SETMASK)
#define CFG_IGRRST_GETMASK          (1<<CFG_IGRRST_OFFSET)
  #define CFG_IGRRST_SETMASK          (1<<CFG_IGRRST_OFFSET)
  #define CFG_IGRRST_CLRMASK          (EXTCFG1_GETALL_MASK & ~CFG_IGRRST_SETMASK)
#define CFG_RSTMASKS_GETMASK        (3<<CFG_RSTMASKS_OFFSET)
  #define CFG_RSTMASKS_RSTMASK        (EXTCFG1_GETALL_MASK & ~CFG_RSTMASKS_GETMASK)
  #define CFG_RSTMASKS_CLRMASK        (EXTCFG1_GETALL_MASK & ~CFG_RSTMASKS_GETMASK)
#define CFG_GAMMA_GETMASK             (0xF<<CFG_GAMMA_OFFSET)
  #define CFG_GAMMASEL_RSTMASK          (EXTCFG1_GETALL_MASK & ~CFG_GAMMA_GETMASK)
  #define CFG_GAMMA_CLRMASK             (EXTCFG1_GETALL_MASK & ~CFG_GAMMA_GETMASK)
#define CFG_DEBLUR_MODE_GETMASK       (1<<CFG_DEBLUR_MODE_OFFSET)
  #define CFG_DEBLUR_MODE_SETMASK       (1<<CFG_DEBLUR_MODE_OFFSET)
  #define CFG_DEBLUR_MODE_CLRMASK       (EXTCFG1_GETALL_MASK & ~CFG_DEBLUR_MODE_GETMASK)
#define CFG_16BITMODE_GETMASK         (1<<CFG_16BITMODE_OFFSET)
  #define CFG_16BITMODE_SETMASK         (1<<CFG_16BITMODE_OFFSET)
  #define CFG_16BITMODE_CLRMASK         (EXTCFG1_GETALL_MASK & ~CFG_16BITMODE_SETMASK)
#define CFG_VERTSHIFT_GETMASK         (0x1F<<CFG_VERTSHIFT_OFFSET)
  #define CFG_VERTSHIFT_RSTMASK         (EXTCFG1_GETALL_MASK & ~CFG_VERTSHIFT_GETMASK)
  #define CFG_VERTSHIFT_CLRMASK         (EXTCFG1_GETALL_MASK & ~CFG_VERTSHIFT_GETMASK)
#define CFG_HORSHIFT_GETMASK          (0x1F<<CFG_HORSHIFT_OFFSET)
  #define CFG_HORSHIFT_RSTMASK          (EXTCFG1_GETALL_MASK & ~CFG_HORSHIFT_GETMASK)
  #define CFG_HORSHIFT_CLRMASK          (EXTCFG1_GETALL_MASK & ~CFG_HORSHIFT_GETMASK)
#define CFG_DEINTER_MODE_GETMASK      (0x3<<CFG_DEINTER_MODE_OFFSET)
  #define CFG_DEINTER_MODE_SETMASK      (0x3<<CFG_DEINTER_MODE_OFFSET)
  #define CFG_DEINTER_MODE_RSTMASK      (EXTCFG1_GETALL_MASK & ~CFG_DEINTER_MODE_GETMASK)
#define CFG_V_INTERP_MODE_GETMASK     (0x3<<CFG_V_INTERP_MODE_OFFSET)
  #define CFG_V_INTERP_MODE_RSTMASK     (EXTCFG1_GETALL_MASK & ~CFG_V_INTERP_MODE_GETMASK)
  #define CFG_V_INTERP_MODE_CLRMASK     (EXTCFG1_GETALL_MASK & ~CFG_V_INTERP_MODE_GETMASK)
#define CFG_H_INTERP_MODE_GETMASK     (0x3<<CFG_H_INTERP_MODE_OFFSET)
  #define CFG_H_INTERP_MODE_RSTMASK     (EXTCFG1_GETALL_MASK & ~CFG_H_INTERP_MODE_GETMASK)
  #define CFG_H_INTERP_MODE_CLRMASK     (EXTCFG1_GETALL_MASK & ~CFG_H_INTERP_MODE_GETMASK)
#define CFG_PAL_BOXED_MODE_GETMASK    (1<<CFG_PAL_BOXED_MODE_OFFSET)
  #define CFG_PAL_BOXED_MODE_SETMASK    (1<<CFG_PAL_BOXED_MODE_OFFSET)
  #define CFG_PAL_BOXED_MODE_CLRMASK    (EXTCFG1_GETALL_MASK & ~CFG_PAL_BOXED_MODE_SETMASK)

// external cfg set 2
#define EXTCFG2_OUT_BASE  CFG_SET2_OUT_BASE

#define CFG_VSL_THICKNESS_OFFSET  28
#define CFG_VSL_PROFILE_OFFSET    26
#define CFG_VSLHYBDEP_OFFSET      21
#define CFG_VSLSTR_OFFSET         17
#define CFG_HSL_THICKNESS_OFFSET  15
#define CFG_HSL_PROFILE_OFFSET    13
#define CFG_HSLHYBDEP_OFFSET       8
#define CFG_HSLSTR_OFFSET          4
#define CFG_VSL_EN_OFFSET          3
#define CFG_HSL_EN_OFFSET          2
#define CFG_H2V_SL_LINK_OFFSET     1
#define CFG_SL_CALC_BASE_OFFSET    0

#define CFG_VSL_THICKNESS_GETMASK   (0x3<<CFG_VSL_THICKNESS_OFFSET)
  #define CFG_VSL_THICKNESS_RSTMASK   (EXTCFG2_GETALL_MASK & ~CFG_VSL_THICKNESS_GETMASK)
  #define CFG_VSL_THICKNESS_CLRMASK   (EXTCFG2_GETALL_MASK & ~CFG_VSL_THICKNESS_GETMASK)
#define CFG_VSL_PROFILE_GETMASK     (0x3<<CFG_VSL_PROFILE_OFFSET)
  #define CFG_VSL_PROFILE_RSTMASK     (EXTCFG2_GETALL_MASK & ~CFG_VSL_PROFILE_GETMASK)
  #define CFG_VSL_PROFILE_CLRMASK     (EXTCFG2_GETALL_MASK & ~CFG_VSL_PROFILE_GETMASK)
#define CFG_VSLHYBDEP_GETMASK       (0x1F<<CFG_VSLHYBDEP_OFFSET)
  #define CFG_VSLHYBDEP_RSTMASK       (EXTCFG2_GETALL_MASK & ~CFG_VSLHYBDEP_GETMASK)
  #define CFG_VSLHYBDEP_CLRMASK       (EXTCFG2_GETALL_MASK & ~CFG_VSLHYBDEP_GETMASK)
#define CFG_VSLSTR_GETMASK          (0xF<<CFG_VSLSTR_OFFSET)
  #define CFG_VSLSTR_RSTMASK          (EXTCFG2_GETALL_MASK & ~CFG_VSLSTR_GETMASK)
  #define CFG_VSLSTR_CLRMASK          (EXTCFG2_GETALL_MASK & ~CFG_VSLSTR_GETMASK)
#define CFG_HSL_THICKNESS_GETMASK   (0x3<<CFG_HSL_THICKNESS_OFFSET)
  #define CFG_HSL_THICKNESS_RSTMASK   (EXTCFG2_GETALL_MASK & ~CFG_HSL_THICKNESS_GETMASK)
  #define CFG_HSL_THICKNESS_CLRMASK  (EXTCFG2_GETALL_MASK & ~CFG_HSL_THICKNESS_GETMASK)
#define CFG_HSL_PROFILE_GETMASK     (0x3<<CFG_HSL_PROFILE_OFFSET)
  #define CFG_HSL_PROFILE_RSTMASK     (EXTCFG2_GETALL_MASK & ~CFG_HSL_PROFILE_GETMASK)
  #define CFG_HSL_PROFILE_CLRMASK     (EXTCFG2_GETALL_MASK & ~CFG_HSL_PROFILE_GETMASK)
#define CFG_HSLHYBDEP_GETMASK       (0x1F<<CFG_HSLHYBDEP_OFFSET)
  #define CFG_HSLHYBDEP_RSTMASK       (EXTCFG2_GETALL_MASK & ~CFG_HSLHYBDEP_GETMASK)
  #define CFG_HSLHYBDEP_CLRMASK       (EXTCFG2_GETALL_MASK & ~CFG_HSLHYBDEP_GETMASK)
#define CFG_HSLSTR_GETMASK          (0xF<<CFG_HSLSTR_OFFSET)
  #define CFG_HSLSTR_RSTMASK          (EXTCFG2_GETALL_MASK & ~CFG_HSLSTR_GETMASK)
  #define CFG_HSLSTR_CLRMASK          (EXTCFG2_GETALL_MASK & ~CFG_HSLSTR_GETMASK)
#define CFG_VSL_EN_GETMASK          (1<<CFG_VSL_EN_OFFSET)
  #define CFG_VSL_EN_SETMASK          (1<<CFG_VSL_EN_OFFSET)
  #define CFG_VSL_EN_CLRMASK          (EXTCFG2_GETALL_MASK & ~CFG_VSL_EN_GETMASK)
#define CFG_HSL_EN_GETMASK          (1<<CFG_HSL_EN_OFFSET)
  #define CFG_HSL_EN_SETMASK          (1<<CFG_HSL_EN_OFFSET)
  #define CFG_HSL_EN_CLRMASK          (EXTCFG2_GETALL_MASK & ~CFG_HSL_EN_GETMASK)
#define CFG_H2V_SL_LINK_GETMASK     (1<<CFG_H2V_SL_LINK_OFFSET)
  #define CFG_H2V_SL_LINK_SETMASK     (1<<CFG_H2V_SL_LINK_OFFSET)
  #define CFG_H2V_SL_LINK_CLRMASK     (EXTCFG2_GETALL_MASK & ~CFG_H2V_SL_LINK_GETMASK)
#define CFG_SL_CALC_BASE_GETMASK    (1<<CFG_SL_CALC_BASE_OFFSET)
  #define CFG_SL_CALC_BASE_SETMASK    (1<<CFG_SL_CALC_BASE_OFFSET)
  #define CFG_SL_CALC_BASE_CLRMASK    (EXTCFG2_GETALL_MASK & ~CFG_SL_CALC_BASE_GETMASK)

// external cfg set 3
#define EXTCFG3_OUT_BASE  CFG_SET3_OUT_BASE

#define CFG_AUDIO_FILTER_BYPASS_OFFSET  7
#define CFG_AUDIO_AMP_OFFSET            2
#define CFG_AUDIO_SWAP_LR_OFFSET        1
#define CFG_AUDIO_SPDIF_EN_OFFSET       0

#define CFG_AUDIO_FILTER_BYPASS_GETMASK   (1<<CFG_AUDIO_FILTER_BYPASS_OFFSET)
  #define CFG_AUDIO_FILTER_BYPASS_SETMASK   (1<<CFG_AUDIO_FILTER_BYPASS_OFFSET)
  #define CFG_AUDIO_FILTER_BYPASS_CLRMASK   (EXTCFG3_GETALL_MASK & ~CFG_AUDIO_FILTER_BYPASS_SETMASK)
#define CFG_AUDIO_AMP_GETMASK             (0x1F<<CFG_AUDIO_AMP_OFFSET)
  #define CFG_AUDIO_AMP_RSTMASK             (EXTCFG3_GETALL_MASK & ~CFG_AUDIO_AMP_GETMASK)
  #define CFG_AUDIO_AMP_CLRMASK             (EXTCFG3_GETALL_MASK & ~CFG_AUDIO_AMP_GETMASK)
#define CFG_AUDIO_SWAP_LR_GETMASK         (1<<CFG_AUDIO_SWAP_LR_OFFSET)
  #define CFG_AUDIO_SWAP_LR_SETMASK         (1<<CFG_AUDIO_SWAP_LR_OFFSET)
  #define CFG_AUDIO_SWAP_LR_CLRMASK         (EXTCFG3_GETALL_MASK & ~CFG_AUDIO_SWAP_LR_SETMASK)
#define CFG_AUDIO_SPDIF_EN_GETMASK        (1<<CFG_AUDIO_SPDIF_EN_OFFSET)
  #define CFG_AUDIO_SPDIF_EN_SETMASK        (1<<CFG_AUDIO_SPDIF_EN_OFFSET)
  #define CFG_AUDIO_SPDIF_EN_CLRMASK        (EXTCFG3_GETALL_MASK & ~CFG_AUDIO_SPDIF_EN_SETMASK)



// some usefull masking
#define CFG_EXTCFG0_GETLINEX_MASK       (CFG_FORCE_5060_GETMASK | CFG_LOWLATENCYMODE_GETMASK | \
                                         CFG_VGAFOR480P_GETMASK | CFG_RESOLUTION_GETMASK)
#define CFG_EXTCFG0_GETNOLINEX_MASK     (EXTCFG0_GETALL_MASK & ~CFG_EXTCFG0_GETLINEX_MASK)

#define CFG_EXTCFG1_GETTIMINGS_MASK     (CFG_VERTSHIFT_GETMASK | CFG_HORSHIFT_GETMASK)
#define CFG_EXTCFG1_GETNONTIMINGS_MASK  (EXTCFG1_GETALL_MASK & ~CFG_EXTCFG1_GETTIMINGS_MASK)

#define CFG_EXTCFG0_GETSCALING_MASK     (CFG_VERTSCALE_GETMASK | CFG_HORSCALE_GETMASK)
#define CFG_EXTCFG0_GETNONSCALING_MASK  (EXTCFG0_GETALL_MASK & ~CFG_EXTCFG0_GETSCALING_MASK)

// some min values
#define CFG_VERTSCALE_NTSC_MIN  240
#define CFG_VERTSCALE_PAL_MIN   288

// some max values
#define CFG_COLORSPACE_MAX_VALUE         2
#define CFG_LINK_HV_SCALE_MAX_VALUE      3
#define CFG_FALLBACK_MAX_VALUE           2

#define CFG_VERTSCALE_MAX_VALUE        2016 // equals 7.00x @ PAL
#define CFG_HORSCALE_MAX_VALUE      (16*CFG_VERTSCALE_MAX_VALUE/9)
#define CFG_FORCE5060_MAX_VALUE           2
#define CFG_RESOLUTION_MAX_VALUE    LineX6W

#define CFG_RSTMASKS_MAX_VALUE          3
#define CFG_GAMMA_MAX_VALUE             8
#define CFG_HORSHIFT_MAX_VALUE         31
#define CFG_VERTSHIFT_MAX_VALUE        31
#define CFG_DEINTER_MODE_MAX_VALUE      2
#define CFG_INTERP_MODE_MAX_VALUE       3

#define CFG_AUDIO_AMP_MAX_VALUE        31
#define CFG_SL_THICKNESS_MAX_VALUE      3
#define CFG_SL_PROFILE_MAX_VALUE        2
#define CFG_SLSTR_MAX_VALUE            15
#define CFG_SLHYBDEP_MAX_VALUE         24


// some default values other than 0 (go into default value of config)
// these are N64 defaults
#define CFG_AUDIO_AMP_DEFAULTVAL              19
  #define CFG_AUDIO_AMP_DEFAULT_SETMASK         (CFG_AUDIO_AMP_DEFAULTVAL << CFG_AUDIO_AMP_OFFSET)
#define CFG_RSTMASKS_DEFAULTVAL                3
  #define CFG_RSTMASKS_DEFAULT_SETMASK          (CFG_RSTMASKS_DEFAULTVAL << CFG_RSTMASKS_OFFSET)
#define CFG_GAMMA_DEFAULTVAL                   5
  #define CFG_GAMMA_DEFAULT_SETMASK             (CFG_GAMMA_DEFAULTVAL << CFG_GAMMA_OFFSET)
#define CFG_DEINTER_MODE_DEFAULTVAL            2
  #define CFG_DEINTER_MODE_DEFAULT_SETMASK      (CFG_DEINTER_MODE_DEFAULTVAL << CFG_DEINTER_MODE_OFFSET)

#define CFG_TIMING_DEFAULTS           (1 << 9 | 1 << 4)
#define CFG_TIMING_DEFAULTS_SHIFTED   (CFG_TIMING_DEFAULTS << CFG_HORSHIFT_OFFSET)

#define CFG_SCALING_NTSC_240_DEFAULT          ( 240 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) |  640)
#define CFG_SCALING_NTSC_240_DEFAULT_SHIFTED  (CFG_SCALING_NTSC_240_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_NTSC_480_DEFAULT          ( 480 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) |  640)
#define CFG_SCALING_NTSC_480_DEFAULT_SHIFTED  (CFG_SCALING_NTSC_480_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_NTSC_720_DEFAULT          ( 720 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) |  960)
#define CFG_SCALING_NTSC_720_DEFAULT_SHIFTED  (CFG_SCALING_NTSC_720_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_NTSC_960_DEFAULT          ( 960 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1280)
#define CFG_SCALING_NTSC_960_DEFAULT_SHIFTED  (CFG_SCALING_NTSC_960_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_NTSC_1080_DEFAULT         (1080 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1440)
#define CFG_SCALING_NTSC_1080_DEFAULT_SHIFTED (CFG_SCALING_NTSC_1080_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_NTSC_1200_DEFAULT         (1200 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1600)
#define CFG_SCALING_NTSC_1200_DEFAULT_SHIFTED (CFG_SCALING_NTSC_1200_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_NTSC_1440_DEFAULT         (1440 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1920)
#define CFG_SCALING_NTSC_1440_DEFAULT_SHIFTED (CFG_SCALING_NTSC_1440_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_288_DEFAULT           ( 288 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) |  640)
#define CFG_SCALING_PAL_288_DEFAULT_SHIFTED   (CFG_SCALING_PAL_288_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_576_DEFAULT           ( 576 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) |  768)
#define CFG_SCALING_PAL_576_DEFAULT_SHIFTED   (CFG_SCALING_PAL_576_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_720_DEFAULT           ( 720 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) |  960)
#define CFG_SCALING_PAL_720_DEFAULT_SHIFTED   (CFG_SCALING_PAL_720_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_960_DEFAULT           ( 936 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1248)
#define CFG_SCALING_PAL_960_DEFAULT_SHIFTED   (CFG_SCALING_PAL_960_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_1080_DEFAULT          (1080 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1440)
#define CFG_SCALING_PAL_1080_DEFAULT_SHIFTED  (CFG_SCALING_PAL_1080_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_1200_DEFAULT          (1224 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1632)
#define CFG_SCALING_PAL_1200_DEFAULT_SHIFTED  (CFG_SCALING_PAL_1200_DEFAULT << CFG_HORSCALE_OFFSET)
#define CFG_SCALING_PAL_1440_DEFAULT          (1440 << (CFG_VERTSCALE_OFFSET-CFG_HORSCALE_OFFSET) | 1920)
#define CFG_SCALING_PAL_1440_DEFAULT_SHIFTED  (CFG_SCALING_PAL_1440_DEFAULT << CFG_HORSCALE_OFFSET)


// default configuration
#define INTCFG0_DEFAULTS            (CFG_DEBLUR_PC_DEFAULT_SETMASK)
#define INTCFG0_DEFAULTS_GETMASK    (CFG_COLORSPACE_GETMASK | CFG_LIMITED_COLORSPACE_GETMASK | CFG_LINK_HV_SCALE_GETMASK | \
                                     CFG_DEBLUR_PC_DEFAULT_GETMASK | CFG_MODE16BIT_PC_DEFAULT_GETMASK)
#define INTCFG0_NODEFAULTS_GETMASK  (INTCFG0_GETALL_MASK & ~INTCFG0_DEFAULTS_GETMASK)

#define EXTCFG0_DEFAULTS_NTSC240P   (CFG_SCALING_NTSC_240_DEFAULT_SHIFTED | CFG_RESOLUTION_240_SETMASK)
#define EXTCFG0_DEFAULTS_NTSC480P   (CFG_SCALING_NTSC_480_DEFAULT_SHIFTED | CFG_RESOLUTION_480_SETMASK)
#define EXTCFG0_DEFAULTS_NTSC1080P  (CFG_SCALING_NTSC_1080_DEFAULT_SHIFTED | CFG_RESOLUTION_1080_SETMASK)
#define EXTCFG0_DEFAULTS_PAL288P    (CFG_SCALING_PAL_288_DEFAULT_SHIFTED | CFG_RESOLUTION_240_SETMASK)
#define EXTCFG0_DEFAULTS_PAL576P    (CFG_SCALING_PAL_576_DEFAULT_SHIFTED | CFG_RESOLUTION_480_SETMASK)
#define EXTCFG0_DEFAULTS_PAL1080P   (CFG_SCALING_PAL_1080_DEFAULT_SHIFTED | CFG_RESOLUTION_1080_SETMASK)
#define EXTCFG0_DEFAULTS_GETMASK    (CFG_VERTSCALE_GETMASK | CFG_HORSCALE_GETMASK | CFG_FORCE_5060_GETMASK | \
                                     CFG_LOWLATENCYMODE_GETMASK | CFG_VGAFOR480P_GETMASK | CFG_RESOLUTION_GETMASK)
#define EXTCFG0_NODEFAULTS_GETMASK  (EXTCFG0_GETALL_MASK & ~EXTCFG0_DEFAULTS_GETMASK)

#define EXTCFG1_DEFAULTS            (CFG_RSTMASKS_DEFAULT_SETMASK | CFG_GAMMA_DEFAULT_SETMASK | \
                                     CFG_DEBLUR_MODE_SETMASK | CFG_DEINTER_MODE_DEFAULT_SETMASK | CFG_TIMING_DEFAULTS_SHIFTED)
#define EXTCFG1_DEFAULTS_GETMASK    (CFG_RSTMASKS_GETMASK | CFG_GAMMA_GETMASK | CFG_DEBLUR_MODE_GETMASK | \
                                     CFG_16BITMODE_GETMASK | CFG_VERTSHIFT_GETMASK | CFG_HORSHIFT_GETMASK | \
                                     CFG_DEINTER_MODE_GETMASK | CFG_V_INTERP_MODE_GETMASK | CFG_H_INTERP_MODE_GETMASK | CFG_PAL_BOXED_MODE_GETMASK)
#define EXTCFG1_NODEFAULTS_GETMASK  (EXTCFG1_GETALL_MASK & ~EXTCFG1_DEFAULTS_GETMASK)

#define EXTCFG2_DEFAULTS            (0x00000000)
#define EXTCFG2_DEFAULTS_GETMASK    (CFG_VSL_EN_GETMASK | CFG_HSL_EN_GETMASK | CFG_H2V_SL_LINK_GETMASK)
#define EXTCFG2_NODEFAULTS_GETMASK  (EXTCFG2_GETALL_MASK & ~EXTCFG2_DEFAULTS_GETMASK)

#define EXTCFG3_DEFAULTS            (CFG_AUDIO_AMP_DEFAULT_SETMASK)
#define EXTCFG3_DEFAULTS_GETMASK    (CFG_AUDIO_AMP_GETMASK)
#define EXTCFG3_NODEFAULTS_GETMASK  (EXTCFG3_GETALL_MASK & ~EXTCFG3_DEFAULTS_GETMASK)


extern configuration_t sysconfig;

extern config_tray_u8_t linex_words[2];

extern config_t swap_led, color_space, limited_colorspace,
                link_hv_scale,deblur_mode_powercycle, mode16bit_powercycle,
                igr_deblur, igr_16bitmode, fallbackmode, autosave;
extern config_t scaling_steps, region_selection,
                timing_selection, scaling_selection,
                copy_direction, lock_menu;

extern config_t vert_scale, hor_scale,
                linex_force_5060, low_latency_mode,
                vga_for_480p, linex_resolution;
extern config_t show_logo, show_osd, mute_osd_tmp,
                igr_reset, rst_masking,
                gamma_lut, deblur_mode, mode16bit,
                vert_shift, hor_shift,
                deinterlace_mode, interpolation_mode_vert, interpolation_mode_hori, pal_boxed_mode;
extern config_t sl_thickness_vert, sl_profile_vert, slhyb_str_vert, sl_str_vert,
                sl_thickness_hori, sl_profile_hori, slhyb_str_hori, sl_str_hori,
                sl_en_vert, sl_en_hori, sl_link_h2v, sl_calc_base;
extern config_t audio_fliter_bypass, audio_amp, audio_swap_lr, audio_spdif_en;

extern bool_t unlock_1440p;


static inline bool_t is_local_cfg(config_t* cfg_data)
  { return cfg_data->cfg_word == NULL;  }

void cfg_toggle_flag(config_t* cfg_data);
void cfg_set_flag(config_t* cfg_data);
void cfg_clear_flag(config_t* cfg_data);
void cfg_inc_value(config_t* cfg_data);
void cfg_dec_value(config_t* cfg_data);
alt_u16 cfg_get_value(config_t* cfg_data,cfg_offon_t get_reference);
void cfg_set_value(config_t* cfg_data, alt_u16 value);
alt_u16 cfgfct_linex(alt_u16 value, bool_t set_value, bool_t ret_reference);
void cfgfct_unlock1440p(bool_t set_value);
alt_u8 cfg_scale_is_predefined(alt_u16 value,bool_t use_vertical);
void cfg_scale_v2h_update(void);
alt_u16 cfgfct_scale(alt_u16 command,bool_t use_vertical,bool_t set_value,bool_t get_reference);
bool_t confirmation_routine(bool_t question_type);
int cfg_save_to_flash(bool_t need_confirm);
int cfg_load_from_flash(bool_t need_confirm);
void cfg_reset_selections(void);
void cfg_store_linex_word(cfg_region_sel_type_t palmode_select);
void cfg_load_linex_word(cfg_region_sel_type_t palmode_select);
void cfg_store_timing_word(cfg_timing_model_sel_type_t timing_select);
void cfg_load_timing_word(cfg_timing_model_sel_type_t timing_select);
void cfg_store_scaling_word(cfg_scaler_in2out_sel_type_t scaling_word_select);
void cfg_load_scaling_word(cfg_scaler_in2out_sel_type_t scaling_word_select);
int cfg_load_defaults(fallback_vmodes_t vmode,bool_t need_confirm);
void cfg_apply_to_logic(void);
void cfg_clear_words(void);
void cfg_update_reference(void);
int cfg_copy_ntsc2pal(void);

#endif /* CONFIG_H_ */
