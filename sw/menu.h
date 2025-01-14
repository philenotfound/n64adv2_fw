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
 * menu.h
 *
 *  Created on: 09.01.2018
 *      Author: Peter Bartmann
 *
 ********************************************************************************/

#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include "system.h"
#include "config.h"
#include "n64.h"
#include "vd_driver.h"


#ifndef MENU_H_
#define MENU_H_

#define OPT_WINDOW_WIDTH  21
//#define OPT_WINDOWCOLOR_BG    BACKGROUNDCOLOR_WHITE
//#define OPT_WINDOWCOLOR_FONT  FONTCOLOR_BLACK

#define CONFIRM_SHOW_CNT_MID  255
#define CONFIRM_SHOW_CNT_LONG 511

extern char szText[];

typedef enum {
  NON = 0,
  MENU_OPEN,
  MENU_MUTE,
  MENU_UNMUTE,
  MENU_CLOSE,
  NEW_OVERLAY,
  NEW_SELECTION,
  NEW_CONF_VALUE,
  CONFIRM_OK,
  CONFIRM_FAILED,
  CONFIRM_ABORTED
} updateaction_t;

typedef enum {
  HOME = 0,
  CONFIG,
  RWDATA,
  N64DEBUG,
  TEXT
} screentype_t;

typedef enum {
  ICONFIG = 0,
  ISUBMENU,
  CFG_FUNC1,
  CFG_FUNC3,
  CFG_FUNC4,
  INFO_RET_FUNC0,
  INFO_RET_FUNC1,
  INFO_RET_FUNC2
} leavetype_t;

typedef struct {
  alt_u8 left;
  alt_u8 right;
} arrowshape_t;

typedef int (*sys_call_type_0)(void);
typedef int (*sys_call_type_1)(bool_t);
typedef int (*sys_call_type_2)(fallback_vmodes_t,bool_t);

typedef void    (*cfgfct_call_type_1)(bool_t);
typedef alt_u16 (*cfgfct_call_type_3)(alt_u16,bool_t,bool_t);
typedef alt_u16 (*cfgfct_call_type_4)(alt_u16,bool_t,bool_t,bool_t);

typedef struct {
  alt_u8              id;
  const arrowshape_t  *arrowshape;
  leavetype_t         leavetype;
  union {
    struct menu         *submenu;
    config_t            *config_value;
    sys_call_type_0     sys_fun_0;
    sys_call_type_1     sys_fun_1;
    sys_call_type_2     sys_fun_2;
    cfgfct_call_type_1  cfgfct_call_1;
    cfgfct_call_type_3  cfgfct_call_3;
    cfgfct_call_type_4  cfgfct_call_4;
  };
} leaves_t;

typedef struct {
  const alt_u8  hoffset;
  const char*   *text;
} overlay_t;


typedef struct menu {
  const screentype_t  type;
  const char*         *header;
  overlay_t           body;
  struct menu         *parent;
  alt_u8              arrow_position;
  alt_u8              current_selection;
  const alt_u8        number_selections;
  leaves_t            leaves[];

} menu_t;

extern alt_u16 message_cnt;
extern menu_t home_menu, vires_screen, debug_screen;

#define DEBUG_IN_MAIN_MENU_SELECTION  6

void val2txt_func(alt_u16 v);
void val2txt_5b_binaryoffset_func(alt_u16 v);
void val2txt_scale_sel_func(alt_u16 v);
void val2txt_hscale_func(alt_u16 v);
void val2txt_vscale_func(alt_u16 v);
void audioamp2txt_func(alt_u16 v);
void flag2set_func(alt_u16 v);
void scanline_str2txt_func(alt_u16 v);
void scanline_hybrstr2txt_func(alt_u16 v);
void gamma2txt_func(alt_u16 v);

void print_current_timing_mode(void);
void print_ctrl_data(void);
void print_confirm_info(alt_u8 type);
void print_1440p_unlock_info(void);
void print_cr_info(void);

void update_vmode_menu(void);
void update_scaling_menu(void);
void update_timing_menu(void);

updateaction_t modify_menu(cmd_t command, menu_t** current_menu);
void print_overlay(menu_t* current_menu);
void print_selection_arrow(menu_t* current_menu);
int update_cfg_screen(menu_t* current_menu);
int update_debug_screen(menu_t* current_menu);

#endif /* MENU_H_ */
