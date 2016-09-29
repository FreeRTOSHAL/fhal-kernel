/*
 * Copyright (c) 2016 Andreas Werner <kernel@andy89.org>
 * 
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation 
 * files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, 
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 */
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
# define configASSERT(x) \
	do{ \
		if(__builtin_expect(!(x), 0)) { \
			portDISABLE_INTERRUPTS(); \
			for(;;); \
		} \
	}while(0)
#endif
#ifdef CONFIG_ASSERT_USER_DEFINED
# define configASSERT(x) ASSERT_USER(x)
#endif
#ifdef CONFIG_ASSERT_DEFAULT_PRINT
/* 
 * __builtin_expect GCC Optimization
 * 
 * Add Branch prediction information assert should always not x
 */
# include <stdio.h>
# define configASSERT(x) \
	do{ \
		if(__builtin_expect(!(x), 0)) { \
			printf("ASSERT FAILT: %s File: %s Line: %d Function: %s\n", #x, __FILE__, __LINE__, __FUNCTION__); \
			portDISABLE_INTERRUPTS(); \
			for(;;); \
		} \
	}while(0)
#endif
#define CONFIG_ASSERT(x) configASSERT(x)

#ifdef CONFIG_CHECK_STACK_OVERFLOW
# ifdef CONFIG_CHECK_FOR_STACK_OVERFLOW_1
#  define configCHECK_FOR_STACK_OVERFLOW 1
# endif
# ifdef CONFIG_CHECK_FOR_STACK_OVERFLOW_2
#  define configCHECK_FOR_STACK_OVERFLOW 2
# endif
#endif

#ifdef CONFIG_GENERATE_RUN_TIME_STATS_DEFAULT
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() do{}while(0)
#define portGET_RUN_TIME_COUNTER_VALUE() xTaskGetTickCount()
#endif

#ifdef CONFIG_CPU_CLOCK_BY_INTERFACE
# include <clock.h>
# define configCPU_CLOCK_HZ clock_getCPUSpeed(clock_init())
#elif defined(CONFIG_CPU_CLOCK_HZ)
# if CONFIG_CPU_CLOCK_HZ == 0
#  error "CONFIG_CPU_CLOCK_HZ shall be grater then 0"
# endif
# define configCPU_CLOCK_HZ CONFIG_CPU_CLOCK_HZ
#endif

/*
 * Config Transofrmation
 */

#if defined(CONFIG_TOTAL_HEAP_SIZE) && (defined(CONFIG_HEAP_1) || defined(CONFIG_HEAP_2) || defined(CONFIG_HEAP_4))
# if (CONFIG_TOTAL_HEAP_SIZE == 0)
#  error "Heap Size == 0"
# else
#  define configTOTAL_HEAP_SIZE CONFIG_TOTAL_HEAP_SIZE
# endif
#elif defined(CONFIG_HEAP_1) && defined(CONFIG_HEAP_2) && defined(CONFIG_HEAP_4)
# error "CONFIG_TOTAL_HEAP_SIZE not defined"
#else
# define configTOTAL_HEAP_SIZE 0
#endif
#ifdef CONFIG_USE_MALLOC_FAILED_HOOK
# define configUSE_MALLOC_FAILED_HOOK 1
#else
# define configUSE_MALLOC_FAILED_HOOK 0
#endif
#ifdef CONFIG_USE_16_BIT_TICKS
# define configUSE_16_BIT_TICKS 1
#else
# define configUSE_16_BIT_TICKS 0
#endif
#ifdef CONFIG_TICK_RATE_HZ
# if CONFIG_TICK_RATE_HZ == 0
#  error "CONFIG_TICK_RATE_HZ == 0"
# endif
# define configTICK_RATE_HZ CONFIG_TICK_RATE_HZ
#else
# error "configTICK_RATE_HZ not defined"
#endif
#ifdef CONFIG_USE_TRACE_FACILITY
# define configUSE_TRACE_FACILITY 1
#else
# define configUSE_TRACE_FACILITY 0
#endif
#ifdef CONFIG_GENERATE_RUN_TIME_STATS
# define configGENERATE_RUN_TIME_STATS 1
#else
# define configGENERATE_RUN_TIME_STATS 0
#endif
#ifdef CONFIG_INCLUDE_uxTaskGetStackHighWaterMark
# define INCLUDE_uxTaskGetStackHighWaterMark 1
#else
# define INCLUDE_uxTaskGetStackHighWaterMark 0
#endif
#ifdef CONFIG_USE_LIST_DATA_INTEGRITY_CHECK_BYTES
# define configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES 1
#else
# define configUSE_LIST_DATA_INTEGRITY_CHECK_BYTES 0
#endif
#ifdef CONFIG_USE_ALTERNATIVE_API
# define configUSE_ALTERNATIVE_API 1
#else
# define configUSE_ALTERNATIVE_API 0
#endif
#ifdef CONFIG_MAX_PRIORITIES
# if CONFIG_MAX_PRIORITIES == 0
#  error "CONFIG_MAX_PRIORITIES shall > 0"
# endif
# define configMAX_PRIORITIES CONFIG_MAX_PRIORITIES
#else
# error "CONFIG_MAX_PRIORITIES not defined"
#endif
#ifdef CONFIG_MINIMAL_STACK_SIZE
# if CONFIG_MINIMAL_STACK_SIZE == 0
#  error "CONFIG_MINIMAL_STACK_SIZE shall > 0"
# endif
# define configMINIMAL_STACK_SIZE CONFIG_MINIMAL_STACK_SIZE
#else
# error "CONFIG_MINIMAL_STACK_SIZE not defined"
#endif
#ifdef CONFIG_MAX_TASK_NAME_LEN
# if CONFIG_MAX_TASK_NAME_LEN == 0
#  error "CONFIG_MAX_TASK_NAME_LEN shall > 0" /* TODO Check if Correct */
# endif
# define configMAX_TASK_NAME_LEN CONFIG_MAX_TASK_NAME_LEN
#else
# error "CONFIG_MAX_TASK_NAME_LEN not defined"
#endif
#ifdef CONFIG_NUM_THREAD_LOCAL_STORAGE_POINTERS
# define configNUM_THREAD_LOCAL_STORAGE_POINTERS CONFIG_NUM_THREAD_LOCAL_STORAGE_POINTERS
#else
# error "CONFIG_NUM_THREAD_LOCAL_STORAGE_POINTERS not defined"
#endif
#ifdef CONFIG_USE_STATS_FORMATTING_FUNCTIONS
# define configUSE_STATS_FORMATTING_FUNCTIONS 1
#else
# define configUSE_STATS_FORMATTING_FUNCTIONS 0
#endif
#ifdef CONFIG_USE_TICKLESS_IDLE
# define configUSE_TICKLESS_IDLE 1
#else
# define configUSE_TICKLESS_IDLE 0
#endif
#ifdef CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP
# if CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP <= 1
#  error "CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP shal > 1"
# endif
# define configEXPECTED_IDLE_TIME_BEFORE_SLEEP CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP
#else
# define configEXPECTED_IDLE_TIME_BEFORE_SLEEP 2
#endif
#ifdef CONFIG_USE_IDLE_HOOK
# define configUSE_IDLE_HOOK 1
#else
# define configUSE_IDLE_HOOK 0
#endif
#ifdef CONFIG_INCLUDE_vTaskSuspend
# define INCLUDE_vTaskSuspend 1
#else
# define INCLUDE_vTaskSuspend 0
#endif
#ifdef CONFIG_INCLUDE_xTaskResumeFromISR
# define INCLUDE_xTaskResumeFromISR 1
#else
# define INCLUDE_xTaskResumeFromISR 0
#endif
#ifdef CONFIG_USE_PREEMPTION
# define configUSE_PREEMPTION 1
#else
# define configUSE_PREEMPTION 0
#endif
#ifdef CONFIG_USE_TIME_SLICING
# define configUSE_TIME_SLICING 1
#else
# define configUSE_TIME_SLICING 0
#endif
#ifdef CONFIG_IDLE_SHOULD_YIELD
# define configIDLE_SHOULD_YIELD 1
#else
# define configIDLE_SHOULD_YIELD 0
#endif
#ifdef CONFIG_USE_APPLICATION_TASK_TAG
# define configUSE_APPLICATION_TASK_TAG 1
#else
# define configUSE_APPLICATION_TASK_TAG 0
#endif
#ifdef CONFIG_USE_NEWLIB_REENTRANT
# define configUSE_NEWLIB_REENTRANT 1
#else
# define configUSE_NEWLIB_REENTRANT 0
#endif
#ifdef CONFIG_USE_TASK_NOTIFICATIONS
# define configUSE_TASK_NOTIFICATIONS 1
#else
# define configUSE_TASK_NOTIFICATIONS 0
#endif
#ifdef CONFIG_USE_PORT_OPTIMISED_TASK_SELECTION
# define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#else
# define configUSE_PORT_OPTIMISED_TASK_SELECTION 0
#endif
#ifdef CONFIG_USE_16_BIT_TICKS
# define configUSE_16_BIT_TICKS 1
#else
# define configUSE_16_BIT_TICKS 0
#endif
#ifdef CONFIG_CHECK_STACK_OVERFLOW
# define configCHECK_STACK_OVERFLOW 1
#else
# define configCHECK_STACK_OVERFLOW 0
#endif
#ifdef CONFIG_USE_TICK_HOOK
# define configUSE_TICK_HOOK 1
#else
# define configUSE_TICK_HOOK 0
#endif
#ifdef CONFIG_INCLUDE_vTaskDelete
# define INCLUDE_vTaskDelete 1
#else
# define INCLUDE_vTaskDelete 0
#endif
#ifdef CONFIG_INCLUDE_xTaskGetIdleTaskHandle
# define INCLUDE_xTaskGetIdleTaskHandle 1
#else
# define INCLUDE_xTaskGetIdleTaskHandle 0
#endif
#ifdef CONFIG_INCLUDE_vTaskDelay
# define INCLUDE_vTaskDelay 1
#else
# define INCLUDE_vTaskDelay 0
#endif
#ifdef CONFIG_INCLUDE_vTaskDelayUntil
# define INCLUDE_vTaskDelayUntil 1
#else
# define INCLUDE_vTaskDelayUntil 0
#endif
#ifdef CONFIG_INCLUDE_eTaskGetState
# define INCLUDE_eTaskGetState 1
#else
# define INCLUDE_eTaskGetState 0
#endif
#ifdef CONFIG_INCLUDE_uxTaskPriorityGet
# define INCLUDE_uxTaskPriorityGet 1
#else
# define INCLUDE_uxTaskPriorityGet 0
#endif
#ifdef CONFIG_INCLUDE_vTaskPrioritySet
# define INCLUDE_vTaskPrioritySet 1
#else
# define INCLUDE_vTaskPrioritySet 0
#endif
#ifdef CONFIG_INCLUDE_pcTaskGetTaskName
# define INCLUDE_pcTaskGetTaskName 1
#else
# define INCLUDE_pcTaskGetTaskName 0
#endif
#ifdef CONFIG_INCLUDE_xTaskGetSchedulerState
# define INCLUDE_xTaskGetSchedulerState 1
#else
# define INCLUDE_xTaskGetSchedulerState 0
#endif
#ifdef CONFIG_INCLUDE_xTaskGetCurrentTaskHandle
# define INCLUDE_xTaskGetCurrentTaskHandle 1
#else
# define INCLUDE_xTaskGetCurrentTaskHandle 0
#endif
#ifdef CONFIG_USE_QUEUE_SETS
# define configUSE_QUEUE_SETS 1
#else
# define configUSE_QUEUE_SETS 0
#endif
#ifdef CONFIG_QUEUE_REGISTRY_SIZE
# define configQUEUE_REGISTRY_SIZE CONFIG_QUEUE_REGISTRY_SIZE
#else
# define configQUEUE_REGISTRY_SIZE 0
#endif
#ifdef CONFIG_USE_MUTEXES
# define configUSE_MUTEXES 1
#else
# define configUSE_MUTEXES 0
#endif
#ifdef CONFIG_INCLUDE_xSemaphoreGetMutexHolder
# define INCLUDE_xSemaphoreGetMutexHolder 1
#else
# define INCLUDE_xSemaphoreGetMutexHolder 0
#endif
#ifdef CONFIG_USE_RECURSIVE_MUTEXES
# define configUSE_RECURSIVE_MUTEXES 1
#else
# define configUSE_RECURSIVE_MUTEXES 0
#endif
#ifdef CONFIG_USE_COUNTING_SEMAPHORES
# define configUSE_COUNTING_SEMAPHORES 1
#else
# define configUSE_COUNTING_SEMAPHORES 0
#endif
#ifdef CONFIG_EVENT_GROUP
# define configEVENT_GROUP 1
#else
# define configEVENT_GROUP 0
#endif
#ifdef CONFIG_INCLUDE_xEventGroupSetBitFromISR
# define INCLUDE_xEventGroupSetBitFromISR 1
#else
# define INCLUDE_xEventGroupSetBitFromISR 0
#endif
#ifdef CONFIG_USE_TIMERS
# define configUSE_TIMERS 1
#else
# define configUSE_TIMERS 0
#endif
#ifdef CONFIG_TIMER_TASK_STACK_DEPTH
# if CONFIG_TIMER_TASK_STACK_DEPTH == 0
#  error CONFIG_TIMER_TASK_STACK_DEPTH > 0
# endif
# define configTIMER_TASK_STACK_DEPTH CONFIG_TIMER_TASK_STACK_DEPTH
#else
# define configTIMER_TASK_STACK_DEPTH 0
#endif
#ifdef CONFIG_TIMER_TASK_PRIORITY
# define configTIMER_TASK_PRIORITY CONFIG_TIMER_TASK_PRIORITY
#else
# define configTIMER_TASK_PRIORITY 0
#endif
#ifdef CONFIG_TIMER_QUEUE_LENGTH
# if CONFIG_TIMER_QUEUE_LENGTH == 0
#  error "CONFIG_TIMER_QUEUE_LENGTH shall be grater then 0"
# endif
# define configTIMER_QUEUE_LENGTH CONFIG_TIMER_QUEUE_LENGTH
#else
# define configTIMER_QUEUE_LENGTH 0
#endif
#ifdef CONFIG_INCLUDE_xTimerPendFunctionCall
# define INCLUDE_xTimerPendFunctionCall 1
#else
# define INCLUDE_xTimerPendFunctionCall 0
#endif
#ifdef CONFIG_INCLUDE_xTimerGetTimerDaemonTaskHandle
# define INCLUDE_xTimerGetTimerDaemonTaskHandle 1
#else 
# define INCLUDE_xTimerGetTimerDaemonTaskHandle 0
#endif
#ifdef CONFIG_USE_CO_ROUTINES
# define configUSE_CO_ROUTINES 1
#else
# define configUSE_CO_ROUTINES 0
#endif
#ifdef CONFIG_MAX_CO_ROUTINE_PRIORITIES
# if CONFIG_MAX_CO_ROUTINE_PRIORITIES == 0
#  error "CONFIG_MAX_CO_ROUTINE_PRIORITIES shall be grater then 0"
# endif
# define configMAX_CO_ROUTINE_PRIORITIES CONFIG_MAX_CO_ROUTINE_PRIORITIES
#else
# define configMAX_CO_ROUTINE_PRIORITIES 0
#endif
/*
 * Arch configs
 */
#ifdef CONFIG_ARCH_ARM
# ifdef CONFIG_SYSTICK_HZ_DIV
#  define configSYSTICK_CLOCK_HZ (configCPU_CLOCK_HZ / CONFIG_SYSTICK_HZ_DIV)
# endif
# if defined(CONFIG_ARCH_ARM_CORTEX_M3) || defined(CONFIG_ARCH_ARM_CORTEX_M4F)
#  ifdef CONFIG_MAX_SYSCALL_INTERRUPT_PRIORITY
#   define configMAX_SYSCALL_INTERRUPT_PRIORITY CONFIG_MAX_SYSCALL_INTERRUPT_PRIORITY
#  else
#   error "Mach do not defined CONFIG_MAX_SYSCALL_INTERRUPT_PRIORITY !!"
#  endif
#  ifdef CONFIG_KERNEL_INTERRUPT_PRIORITY
#   define configKERNEL_INTERRUPT_PRIORITY CONFIG_KERNEL_INTERRUPT_PRIORITY
#  else
#   error "Mach do not defined CONFIG_KERNEL_INTERRUPT_PRIORITY !!"
#  endif
# endif
#endif
#endif
