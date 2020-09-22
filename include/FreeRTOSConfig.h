/* SPDX-License-Identifier: MIT */
/*
 * Author: Andreas Werner <kernel@andy89.org>
 * Date: 2016
 */
#ifndef FreeRTOSConfig_h_
#define FreeRTOSConfig_h_
#ifdef CONFIG_INCLUDE_USER_FREERTOS_CONFIG
# include <FreeRTOSConfigUser.h>
#endif
#ifdef CONFIG_USER_ERROR_FUNCTION
void userErrorHandler();
#define USER_ERROR_HANDLER() userErrorHandler()
#else
#define USER_ERROR_HANDLER()
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
			USER_ERROR_HANDLER(); \
			portDISABLE_INTERRUPTS(); \
			for(;;); \
		} \
	}while(0)
#endif
#ifdef CONFIG_ASSERT_USER_DEFINED
# define configASSERT(x) ASSERT_USER(x)
#endif
#ifdef CONFIG_GCC_BACKTRACE
# include <backtrace.h>
# define BACKTRACE() backtrace();
#else
# define BACKTRACE()
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
			BACKTRACE(); \
			USER_ERROR_HANDLER(); \
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

#ifdef CONFIG_RECORD_STACK_HIGH_ADDRESS
# define configRECORD_STACK_HIGH_ADDRESS 1
#else
# define configRECORD_STACK_HIGH_ADDRESS 0
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
#ifdef CONFIG_INCLUDE_uxTaskGetStackHighWaterMark2
# define INCLUDE_uxTaskGetStackHighWaterMark2 1
#else
# define INCLUDE_uxTaskGetStackHighWaterMark2 0
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
#ifdef CONFIG_PRE_SUPPRESS_TICKS_AND_SLEEP_PROCESSING_FUNCTION
# define configPRE_SUPPRESS_TICKS_AND_SLEEP_PROCESSING(x) do { x = pre_suppress_ticks_and_processing(x)} while(0)
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
#ifdef CONFIG_STACK_DEPTH_TYPE_16BIT
# define configSTACK_DEPTH_TYPE uint16_t
#endif
#ifdef CONFIG_STACK_DEPTH_TYPE_32BIT
# define configSTACK_DEPTH_TYPE uint32_t
#endif
#define configINITIAL_TICK_COUNT CONFIG_INITIAL_TICK_COUNT
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
#ifdef CONFIG_INCLUDE_FREERTOS_TASK_C_ADDITIONS_H
# define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H 1
#else
# define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H 0
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
#ifdef CONFIG_SUPPORT_DYNAMIC_ALLOCATION
# define configSUPPORT_DYNAMIC_ALLOCATION 1
#else
# define configSUPPORT_DYNAMIC_ALLOCATION 0
#endif
#ifdef CONFIG_SUPPORT_STATIC_ALLOCATION
# define configSUPPORT_STATIC_ALLOCATION 1
#else
# define configSUPPORT_STATIC_ALLOCATION 0
#endif
#ifdef CONFIG_APPLICATION_ALLOCATED_HEAP
# define configAPPLICATION_ALLOCATED_HEAP 1
#else
# define configAPPLICATION_ALLOCATED_HEAP 0
#endif
#ifdef CONFIG_USE_POSIX_ERRNO
# define configUSE_POSIX_ERRNO 1
#else
# define configUSE_POSIX_ERRNO 0
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
#ifdef CONFIG_ARCH_SUPPORT_CUSTOM_TASK_RETURN_ADDRESS
void taskReturnFunction();
# define configTASK_RETURN_ADDRESS taskReturnFunction
#endif
#endif
#ifdef CONFIG_ENABLE_MPU
# define configENABLE_MPU 1
#else
# define configENABLE_MPU 0
#endif
#ifdef CONFIG_ENABLE_FPU
# define configENABLE_FPU 1
#else
# define configENABLE_FPU 0
#endif
#ifdef CONFIG_ENABLE_TRUSTZONE
# define configENABLE_TRUSTZONE 1
#else
# define configENABLE_TRUSTZONE 0
#endif
#ifdef CONFIG_RUN_FREERTOS_SECURE_ONLY
# define configRUN_FREERTOS_SECURE_ONLY 1
#else
# define configRUN_FREERTOS_SECURE_ONLY 0
#endif
#ifdef CONFIG_INCLUDE_xTaskAbortDelay
# define INCLUDE_xTaskAbortDelay 1
#else
# define INCLUDE_xTaskAbortDelay 0
#endif
