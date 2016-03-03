#ifndef FreeRTOSConfig_h_
#define FreeRTOSConfig_h_
#ifdef CONFIG_INCLUDE_USER_FREERTOS_CONFIG
# include <FreeRTOSConfigUser.h>
#endif
#ifdef CONFIG_ASSERT_DEFAULT
/* 
 * __builtin_expect GCC Optimization 
 * 
 * Add Branch prediction information assert should always not x
 */
# define CONFIG_ASSERT(x) \
	do{ \
		if(__builtin_expect(!(x), 0)) { \
			taskDISABLE_INTERRUPTS(); \
			for(;;); \
		} \
	}while(0)
#endif
#ifdef CONFIG_CHECK_STACK_OVERFLOW
# ifdef CONFIG_CHECK_FOR_STACK_OVERFLOW_1
#  define CONFIG_CHECK_FOR_STACK_OVERFLOW 1
# endif
# ifdef CONFIG_CHECK_FOR_STACK_OVERFLOW_2
#  define CONFIG_CHECK_FOR_STACK_OVERFLOW 2
# endif
#endif
#ifdef CONFIG_ASSERT_USER_DEFINED
# define CONFIG_ASSERT(x) ASSERT_USER(x)
#endif

#ifdef CONFIG_GENERATE_RUN_TIME_STATS_DEFAULT
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() do{}while(0)
#define portGET_RUN_TIME_COUNTER_VALUE() xTaskGetTickCount()
#endif

#ifndef CONFIG_USE_PREEMPTION
# define CONFIG_USE_PREEMPTION 0
#endif
#ifndef CONFIG_USE_IDLE_HOOK
# define CONFIG_USE_IDLE_HOOK 0
#endif
#ifndef CONFIG_USE_TICK_HOOK
# define CONFIG_USE_TICK_HOOK 0
#endif
#ifndef INCLUDE_vTaskPrioritySet 
# define INCLUDE_vTaskPrioritySet 0 
#endif
#ifndef INCLUDE_uxTaskPriorityGet
# define INCLUDE_uxTaskPriorityGet 0
#endif
#ifndef INCLUDE_vTaskDelete 
# define INCLUDE_vTaskDelete 0 
#endif
#ifndef INCLUDE_vTaskSuspend
# define INCLUDE_vTaskSuspend 0
#endif
#ifndef INCLUDE_vTaskDelayUntil
# define INCLUDE_vTaskDelayUntil 0 
#endif 
#ifndef INCLUDE_vTaskDelay
# define INCLUDE_vTaskDelay 0 
#endif 
#ifndef CONFIG_USE_16_BIT_TICKS 
# define CONFIG_USE_16_BIT_TICKS 0
#endif 
#ifndef CONFIG_MAX_PRIORITIES 
# define CONFIG_MAX_PRIORITIES 0
#endif 
#ifndef CONFIG_USE_CO_ROUTINES
# define CONFIG_USE_CO_ROUTINES 0
#endif
#ifndef CONFIG_INCLUDE_vTaskDelete
# define CONFIG_INCLUDE_vTaskDelete 0
#endif
#ifndef CONFIG_INCLUDE_xTaskGetIdleTaskHandle
# define CONFIG_INCLUDE_xTaskGetIdleTaskHandle 0
#endif
#ifndef CONFIG_INCLUDE_eTaskGetState 
# define CONFIG_INCLUDE_eTaskGetState 0 
#endif
#ifndef CONFIG_INCLUDE_uxTaskPriorityGet 
# define CONFIG_INCLUDE_uxTaskPriorityGet 0
#endif
#ifndef CONFIG_INCLUDE_uxTaskPriorityGet
# define CONFIG_INCLUDE_uxTaskPriorityGet 0
#endif
#ifndef CONFIG_INCLUDE_vTaskPrioritySet 
# define CONFIG_INCLUDE_vTaskPrioritySet 0
#endif
#ifndef CONFIG_INCLUDE_xTaskResumeFromISR
# define CONFIG_INCLUDE_xTaskResumeFromISR 0 
#endif
#ifndef CONFIG_INCLUDE_pcTaskGetTaskName 
# define CONFIG_INCLUDE_pcTaskGetTaskName 0 
#endif
#ifndef CONFIG_INCLUDE_uxTaskGetStackHighWaterMark
# define CONFIG_INCLUDE_uxTaskGetStackHighWaterMark 0
#endif
#ifndef CONFIG_INCLUDE_xTaskGetCurrentTaskHandle 
# define CONFIG_INCLUDE_xTaskGetCurrentTaskHandle 0
#endif
#ifndef CONFIG_INCLUDE_xTaskGetSchedulerState
# define CONFIG_INCLUDE_xTaskGetSchedulerState 0 
#endif
#ifndef CONFIG_INCLUDE_vTaskSuspend
# define CONFIG_INCLUDE_vTaskSuspend 0
#endif
#ifndef CONFIG_INCLUDE_vTaskDelayUntil
# define CONFIG_INCLUDE_vTaskDelayUntil 0
#endif
#ifndef CONFIG_INCLUDE_vTaskDelay
# define CONFIG_INCLUDE_vTaskDelay 0 
#endif
#ifndef CONFIG_INCLUDE_xTimerPendFunctionCall
# define CONFIG_INCLUDE_xTimerPendFunctionCall 0
#endif
#ifndef CONFIG_INCLUDE_xTimerGetTimerDaemonTaskHandle
# define CONFIG_INCLUDE_xTimerGetTimerDaemonTaskHandle 0
#endif
#ifndef CONFIG_INCLUDE_xSemaphoreGetMutexHolder
# define CONFIG_INCLUDE_xSemaphoreGetMutexHolder 0
#endif

#ifdef CONFIG_CPU_CLOCK_BY_INTERFACE
# include <clock.h>
# define CONFIG_CPU_CLOCK_HZ clock_getCPUSpeed(clock_init())
#endif

#endif
