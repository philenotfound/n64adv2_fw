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
 * si5356.c
 *
 *  Created on: 12.03.2021
 *      Author: Peter Bartmann
 *
 * File created with the help of ClockBuilder Pro v2.29 [2018-11-04]
 *
 ********************************************************************************/

#include "unistd.h"
#include "alt_types.h"
#include "i2c_opencores.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

#include "si5356.h"
#include "si5356_regs_p.h"
#include "i2c.h"
#include "config.h"
#include "n64.h"
#include "led.h"

#define PLL_LOCK_MAXWAIT_US         1000
#define PLL_LOCK_2_FPGA_TIMEOUT_US  150


#define si5356_reg_bitset(regaddr,bit)   i2c_reg_bitset(SI5356_I2C_BASE,regaddr,bit)
#define si5356_reg_bitclear(regaddr,bit) i2c_reg_bitclear(SI5356_I2C_BASE,regaddr,bit)
#define si5356_readreg(regaddr)          i2c_readreg(SI5356_I2C_BASE,regaddr)
#define si5356_writereg(regaddr,data)    i2c_writereg(SI5356_I2C_BASE,regaddr,data)


int check_si5356()
{
  alt_u8 retval = si5356_readreg(0x00);
  if ( retval == 0xff) return -SI5356_INIT_FAILED_0;
  retval &= 0x07;
  if (retval > 1) return -SI5356_INIT_FAILED_1;
  return 0;
}

bool_t configure_clk_si5356(clk_config_t target_cfg) {
  led_drive(LED_NOK, LED_ON); // LED must be cleared from outside
  periphals_clr_ready_bit();  // must be set again from external
  
  int i;
  si5356_writereg(OEB_REG,OEB_REG_VAL_OFF); // disable outputs
  
  si_clk_src_t clk_src = target_cfg < FREE_240p_288p;
  for (i=0; i<NUM_INPSW_REGS; i++)
    if (inpsw_regs[i].reg_mask == 0xFF) si5356_writereg(inpsw_regs[i].reg_addr,inpsw_regs[i].reg_val[clk_src]);
    else                                si5356_writereg(inpsw_regs[i].reg_addr,(inpsw_regs[i].reg_val[clk_src] & inpsw_regs[i].reg_mask) | (si5356_readreg(inpsw_regs[i].reg_addr) & ~inpsw_regs[i].reg_mask));
  
  for (i=0; i<NUM_CFG_MODE_REGS; i++)
    si5356_writereg(si_mode_regs[i].reg_addr,si_mode_regs[i].reg_val[target_cfg]);

//  si5356_reg_bitset(SOFT_RST_REG,SOFT_RST_BIT);   // soft reset
  si5356_writereg(SOFT_RST_REG,(1<<SOFT_RST_BIT));  // soft reset
  if (target_cfg == FREE_240p_288p)
    si5356_writereg(OEB_REG,OEB_REG_VAL_SINGLE_ON); // enable outputs
  else
    si5356_writereg(OEB_REG,OEB_REG_VAL_ALL_ON);    // enable outputs
  
  i = PLL_LOCK_MAXWAIT_US;
  while (!SI5356_PLL_LOCKSTATUS()) {  // wait for PLL lock
    if (i == 0) return FALSE;
    usleep(1);
    i--;
  };
  usleep(PLL_LOCK_2_FPGA_TIMEOUT_US);
  return TRUE;
}

bool_t init_si5356(clk_config_t target_cfg) {
  periphals_clr_ready_bit();  // must be set again from external
  int i;

  si5356_writereg(OEB_REG,OEB_REG_VAL_OFF);     // disable outputs
  si5356_writereg(DIS_LOL_REG,DIS_LOL_REG_VAL); // write needed for proper operation

  for (i=0; i<NUM_INIT_REGS; i++)
    if (init_regs[i].reg_mask == 0xFF) si5356_writereg(init_regs[i].reg_addr,init_regs[i].reg_val);
    else                               si5356_writereg(init_regs[i].reg_addr,(init_regs[i].reg_val & init_regs[i].reg_mask) | (si5356_readreg(init_regs[i].reg_addr) & ~init_regs[i].reg_mask));

  return configure_clk_si5356(target_cfg);
}
