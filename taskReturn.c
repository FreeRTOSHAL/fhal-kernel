/* SPDX-License-Identifier: MIT */
/*
 * Author: Andreas Werner <kernel@andy89.org>
 * Date: 2018
 */
#include <FreeRTOS.h>
#include <task.h>
void taskReturnFunction() {
	/* Stop over Assert */
	CONFIG_ASSERT(0);
	/* if assert is disabled: */
	taskDISABLE_INTERRUPTS(); /* Disable all Interrupts */
	for(;;);
}
