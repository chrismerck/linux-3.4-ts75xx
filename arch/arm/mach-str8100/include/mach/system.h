/*******************************************************************************
 *
 *  Copyright (c) 2008 Cavium Networks 
 * 
 *  This file is free software; you can redistribute it and/or modify 
 *  it under the terms of the GNU General Public License, Version 2, as 
 *  published by the Free Software Foundation. 
 *
 *  This file is distributed in the hope that it will be useful, 
 *  but AS-IS and WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, TITLE, or 
 *  NONINFRINGEMENT.  See the GNU General Public License for more details. 
 *
 *  You should have received a copy of the GNU General Public License 
 *  along with this file; if not, write to the Free Software 
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA or 
 *  visit http://www.gnu.org/licenses/. 
 *
 *  This file may also be available under a different license from Cavium. 
 *  Contact Cavium Networks for more information
 *
 ******************************************************************************/

#ifndef __ASM_ARCH_SYSTEM_H__
#define __ASM_ARCH_SYSTEM_H__

#include <mach/star_powermgt.h>
#include <mach/star_timer.h>

static inline void arch_idle(void)
{
	volatile u32 dst= (*((u32 volatile *)(SYSVA_FLASH_BASE_ADDR + 0x20000)));

// local_irq_enable();

	cpu_do_idle();
}

static inline void arch_reset(char mode, const char *cmd)
{
	HAL_PWRMGT_GLOBAL_SOFTWARE_RESET();
}

extern u64 volatile str8100_counter_tick;
static inline u64 str8100_read_counter(void)
{
        return (str8100_counter_tick + TIMER2_COUNTER_REG);
}

#endif