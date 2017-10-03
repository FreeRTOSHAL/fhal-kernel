#include "FreeRTOS.h"


static StaticTask_t xIdleTaskTCB;
static StackType_t uxIdleTaskStack[CONFIG_MINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize)
{
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
	*ppxIdleTaskStackBuffer = uxIdleTaskStack;
	*pulIdleTaskStackSize = CONFIG_MINIMAL_STACK_SIZE;
}
#ifdef CONFIG_USE_TIMERS
static StaticTask_t xTimerTaskTCB;
static StackType_t uxTimerTaskStack[CONFIG_TIMER_TASK_STACK_DEPTH];
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize)  {
	*ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
	*ppxTimerTaskStackBuffer = uxTimerTaskStack;
	*pulTimerTaskStackSize = CONFIG_TIMER_TASK_STACK_DEPTH;
}
#endif
