/*
    FreeRTOS V8.2.3 - Copyright (C) 2015 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined CONFIG_ASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

#ifndef INC_FREERTOS_H
#define INC_FREERTOS_H

/*
 * Include the generic headers required for the FreeRTOS port being used.
 */
#include <stddef.h>

/*
 * If stdint.h cannot be located then:
 *   + If using GCC ensure the -nostdint options is *not* being used.
 *   + Ensure the project's include path includes the directory in which your
 *     compiler stores stdint.h.
 *   + Set any compiler options necessary for it to support C99, as technically
 *     stdint.h is only mandatory with C99 (FreeRTOS does not require C99 in any
 *     other way).
 *   + The FreeRTOS download includes a simple stdint.h definition that can be
 *     used in cases where none is provided by the compiler.  The files only
 *     contains the typedefs required to build FreeRTOS.  Read the instructions
 *     in FreeRTOS/source/stdint.readme for more information.
 */
#include <stdint.h> /* READ COMMENT ABOVE. */

#ifdef __cplusplus
extern "C" {
#endif

/* Application specific CONFIG_uration options. */
#include "FreeRTOSConfig.h"

/* Basic FreeRTOS definitions. */
#include "projdefs.h"

/* Definitions specific to the port being used. */
#include "portable.h"

/*
 * Check all the required application specific macros have been defined.
 * These macros are application specific and (as downloaded) are defined
 * within FreeRTOSConfig.h.
 */

#ifndef CONFIG_MINIMAL_STACK_SIZE
	#error Missing definition:  CONFIG_MINIMAL_STACK_SIZE must be defined in FreeRTOSConfig.h.  CONFIG_MINIMAL_STACK_SIZE defines the size (in words) of the stack allocated to the idle task.  Refer to the demo project provided for your port for a suitable value.
#endif

#ifndef CONFIG_MAX_PRIORITIES
	#error Missing definition:  CONFIG_MAX_PRIORITIES must be defined in FreeRTOSConfig.h.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_USE_PREEMPTION
	#error Missing definition:  CONFIG_USE_PREEMPTION must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_USE_IDLE_HOOK
	#error Missing definition:  CONFIG_USE_IDLE_HOOK must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_USE_TICK_HOOK
	#error Missing definition:  CONFIG_USE_TICK_HOOK must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_INCLUDE_vTaskPrioritySet
	#error Missing definition:  CONFIG_INCLUDE_vTaskPrioritySet must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_INCLUDE_uxTaskPriorityGet
	#error Missing definition:  CONFIG_INCLUDE_uxTaskPriorityGet must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_INCLUDE_vTaskDelete
	#error Missing definition:  CONFIG_INCLUDE_vTaskDelete must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_INCLUDE_vTaskSuspend
	#error Missing definition:  CONFIG_INCLUDE_vTaskSuspend must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_INCLUDE_vTaskDelayUntil
	#error Missing definition:  CONFIG_INCLUDE_vTaskDelayUntil must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_INCLUDE_vTaskDelay
	#error Missing definition:  CONFIG_INCLUDE_vTaskDelay must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_USE_16_BIT_TICKS
	#error Missing definition:  CONFIG_USE_16_BIT_TICKS must be defined in FreeRTOSConfig.h as either 1 or 0.  See the Configuration section of the FreeRTOS API documentation for details.
#endif

#ifndef CONFIG_MAX_PRIORITIES
	#error CONFIG_MAX_PRIORITIES must be defined to be greater than or equal to 1.
#endif

#ifndef CONFIG_USE_CO_ROUTINES
	#define CONFIG_USE_CO_ROUTINES 0
#endif

#if CONFIG_USE_CO_ROUTINES != 0
	#ifndef CONFIG_MAX_CO_ROUTINE_PRIORITIES
		#error CONFIG_MAX_CO_ROUTINE_PRIORITIES must be greater than or equal to 1.
	#endif
#endif

#ifndef CONFIG_INCLUDE_xTaskGetIdleTaskHandle
	#define CONFIG_INCLUDE_xTaskGetIdleTaskHandle 0
#endif

#ifndef CONFIG_INCLUDE_xTimerGetTimerDaemonTaskHandle
	#define CONFIG_INCLUDE_xTimerGetTimerDaemonTaskHandle 0
#endif

#ifndef CONFIG_INCLUDE_xQueueGetMutexHolder
	#define CONFIG_INCLUDE_xQueueGetMutexHolder 0
#endif

#ifndef CONFIG_INCLUDE_xSemaphoreGetMutexHolder
	#define CONFIG_INCLUDE_xSemaphoreGetMutexHolder CONFIG_INCLUDE_xQueueGetMutexHolder
#endif

#ifndef CONFIG_INCLUDE_pcTaskGetTaskName
	#define CONFIG_INCLUDE_pcTaskGetTaskName 0
#endif

#ifndef CONFIG_USE_APPLICATION_TASK_TAG
	#define CONFIG_USE_APPLICATION_TASK_TAG 0
#endif

#ifndef CONFIG_NUM_THREAD_LOCAL_STORAGE_POINTERS
	#define CONFIG_NUM_THREAD_LOCAL_STORAGE_POINTERS 0
#endif

#ifndef CONFIG_INCLUDE_uxTaskGetStackHighWaterMark
	#define CONFIG_INCLUDE_uxTaskGetStackHighWaterMark 0
#endif

#ifndef CONFIG_INCLUDE_eTaskGetState
	#define CONFIG_INCLUDE_eTaskGetState 0
#endif

#ifndef CONFIG_USE_RECURSIVE_MUTEXES
	#define CONFIG_USE_RECURSIVE_MUTEXES 0
#endif

#ifndef CONFIG_USE_MUTEXES
	#define CONFIG_USE_MUTEXES 0
#endif

#ifndef CONFIG_USE_TIMERS
	#define CONFIG_USE_TIMERS 0
#endif

#ifndef CONFIG_USE_COUNTING_SEMAPHORES
	#define CONFIG_USE_COUNTING_SEMAPHORES 0
#endif

#ifndef CONFIG_USE_ALTERNATIVE_API
	#define CONFIG_USE_ALTERNATIVE_API 0
#endif

#ifndef portCRITICAL_NESTING_IN_TCB
	#define portCRITICAL_NESTING_IN_TCB 0
#endif

#ifndef CONFIG_MAX_TASK_NAME_LEN
	#define CONFIG_MAX_TASK_NAME_LEN 16
#endif

#ifndef CONFIG_IDLE_SHOULD_YIELD
	#define CONFIG_IDLE_SHOULD_YIELD		1
#endif

#if CONFIG_MAX_TASK_NAME_LEN < 1
	#error CONFIG_MAX_TASK_NAME_LEN must be set to a minimum of 1 in FreeRTOSConfig.h
#endif

#ifndef CONFIG_INCLUDE_xTaskResumeFromISR
	#define CONFIG_INCLUDE_xTaskResumeFromISR 1
#endif

#ifndef CONFIG_INCLUDE_xEventGroupSetBitFromISR
	#define CONFIG_INCLUDE_xEventGroupSetBitFromISR 0
#endif

#ifndef CONFIG_INCLUDE_xTimerPendFunctionCall
	#define CONFIG_INCLUDE_xTimerPendFunctionCall 0
#endif

#ifndef CONFIG_ASSERT
	#define CONFIG_ASSERT( x )
	#define CONFIG_ASSERT_DEFINED 0
#else
	#define CONFIG_ASSERT_DEFINED 1
#endif

/* The timers module relies on xTaskGetSchedulerState(). */
#if CONFIG_USE_TIMERS == 1

	#ifndef CONFIG_TIMER_TASK_PRIORITY
		#error If CONFIG_USE_TIMERS is set to 1 then CONFIG_TIMER_TASK_PRIORITY must also be defined.
	#endif /* CONFIG_TIMER_TASK_PRIORITY */

	#ifndef CONFIG_TIMER_QUEUE_LENGTH
		#error If CONFIG_USE_TIMERS is set to 1 then CONFIG_TIMER_QUEUE_LENGTH must also be defined.
	#endif /* CONFIG_TIMER_QUEUE_LENGTH */

	#ifndef CONFIG_TIMER_TASK_STACK_DEPTH
		#error If CONFIG_USE_TIMERS is set to 1 then CONFIG_TIMER_TASK_STACK_DEPTH must also be defined.
	#endif /* CONFIG_TIMER_TASK_STACK_DEPTH */

#endif /* CONFIG_USE_TIMERS */

#ifndef CONFIG_INCLUDE_xTaskGetSchedulerState
	#define CONFIG_INCLUDE_xTaskGetSchedulerState 0
#endif

#ifndef CONFIG_INCLUDE_xTaskGetCurrentTaskHandle
	#define CONFIG_INCLUDE_xTaskGetCurrentTaskHandle 0
#endif


#ifndef portSET_INTERRUPT_MASK_FROM_ISR
	#define portSET_INTERRUPT_MASK_FROM_ISR() 0
#endif

#ifndef portCLEAR_INTERRUPT_MASK_FROM_ISR
	#define portCLEAR_INTERRUPT_MASK_FROM_ISR( uxSavedStatusValue ) ( void ) uxSavedStatusValue
#endif

#ifndef portCLEAN_UP_TCB
	#define portCLEAN_UP_TCB( pxTCB ) ( void ) pxTCB
#endif

#ifndef portPRE_TASK_DELETE_HOOK
	#define portPRE_TASK_DELETE_HOOK( pvTaskToDelete, pxYieldPending )
#endif

#ifndef portSETUP_TCB
	#define portSETUP_TCB( pxTCB ) ( void ) pxTCB
#endif

#ifndef CONFIG_QUEUE_REGISTRY_SIZE
	#define CONFIG_QUEUE_REGISTRY_SIZE 0U
#endif

#if ( CONFIG_QUEUE_REGISTRY_SIZE < 1 )
	#define vQueueAddToRegistry( xQueue, pcName )
	#define vQueueUnregisterQueue( xQueue )
#endif

#ifndef portPOINTER_SIZE_TYPE
	#define portPOINTER_SIZE_TYPE uint32_t
#endif

/* Remove any unused trace macros. */
#ifndef traceSTART
	/* Used to perform any necessary initialisation - for example, open a file
	into which trace is to be written. */
	#define traceSTART()
#endif

#ifndef traceEND
	/* Use to close a trace, for example close a file into which trace has been
	written. */
	#define traceEND()
#endif

#ifndef traceTASK_SWITCHED_IN
	/* Called after a task has been selected to run.  pxCurrentTCB holds a pointer
	to the task control block of the selected task. */
	#define traceTASK_SWITCHED_IN()
#endif

#ifndef traceINCREASE_TICK_COUNT
	/* Called before stepping the tick count after waking from tickless idle
	sleep. */
	#define traceINCREASE_TICK_COUNT( x )
#endif

#ifndef traceLOW_POWER_IDLE_BEGIN
	/* Called immediately before entering tickless idle. */
	#define traceLOW_POWER_IDLE_BEGIN()
#endif

#ifndef	traceLOW_POWER_IDLE_END
	/* Called when returning to the Idle task after a tickless idle. */
	#define traceLOW_POWER_IDLE_END()
#endif

#ifndef traceTASK_SWITCHED_OUT
	/* Called before a task has been selected to run.  pxCurrentTCB holds a pointer
	to the task control block of the task being switched out. */
	#define traceTASK_SWITCHED_OUT()
#endif

#ifndef traceTASK_PRIORITY_INHERIT
	/* Called when a task attempts to take a mutex that is already held by a
	lower priority task.  pxTCBOfMutexHolder is a pointer to the TCB of the task
	that holds the mutex.  uxInheritedPriority is the priority the mutex holder
	will inherit (the priority of the task that is attempting to obtain the
	muted. */
	#define traceTASK_PRIORITY_INHERIT( pxTCBOfMutexHolder, uxInheritedPriority )
#endif

#ifndef traceTASK_PRIORITY_DISINHERIT
	/* Called when a task releases a mutex, the holding of which had resulted in
	the task inheriting the priority of a higher priority task.
	pxTCBOfMutexHolder is a pointer to the TCB of the task that is releasing the
	mutex.  uxOriginalPriority is the task's CONFIG_ured (base) priority. */
	#define traceTASK_PRIORITY_DISINHERIT( pxTCBOfMutexHolder, uxOriginalPriority )
#endif

#ifndef traceBLOCKING_ON_QUEUE_RECEIVE
	/* Task is about to block because it cannot read from a
	queue/mutex/semaphore.  pxQueue is a pointer to the queue/mutex/semaphore
	upon which the read was attempted.  pxCurrentTCB points to the TCB of the
	task that attempted the read. */
	#define traceBLOCKING_ON_QUEUE_RECEIVE( pxQueue )
#endif

#ifndef traceBLOCKING_ON_QUEUE_SEND
	/* Task is about to block because it cannot write to a
	queue/mutex/semaphore.  pxQueue is a pointer to the queue/mutex/semaphore
	upon which the write was attempted.  pxCurrentTCB points to the TCB of the
	task that attempted the write. */
	#define traceBLOCKING_ON_QUEUE_SEND( pxQueue )
#endif

#ifndef CONFIG_CHECK_FOR_STACK_OVERFLOW
	#define CONFIG_CHECK_FOR_STACK_OVERFLOW 0
#endif

/* The following event macros are embedded in the kernel API calls. */

#ifndef traceMOVED_TASK_TO_READY_STATE
	#define traceMOVED_TASK_TO_READY_STATE( pxTCB )
#endif

#ifndef traceQUEUE_CREATE
	#define traceQUEUE_CREATE( pxNewQueue )
#endif

#ifndef traceQUEUE_CREATE_FAILED
	#define traceQUEUE_CREATE_FAILED( ucQueueType )
#endif

#ifndef traceCREATE_MUTEX
	#define traceCREATE_MUTEX( pxNewQueue )
#endif

#ifndef traceCREATE_MUTEX_FAILED
	#define traceCREATE_MUTEX_FAILED()
#endif

#ifndef traceGIVE_MUTEX_RECURSIVE
	#define traceGIVE_MUTEX_RECURSIVE( pxMutex )
#endif

#ifndef traceGIVE_MUTEX_RECURSIVE_FAILED
	#define traceGIVE_MUTEX_RECURSIVE_FAILED( pxMutex )
#endif

#ifndef traceTAKE_MUTEX_RECURSIVE
	#define traceTAKE_MUTEX_RECURSIVE( pxMutex )
#endif

#ifndef traceTAKE_MUTEX_RECURSIVE_FAILED
	#define traceTAKE_MUTEX_RECURSIVE_FAILED( pxMutex )
#endif

#ifndef traceCREATE_COUNTING_SEMAPHORE
	#define traceCREATE_COUNTING_SEMAPHORE()
#endif

#ifndef traceCREATE_COUNTING_SEMAPHORE_FAILED
	#define traceCREATE_COUNTING_SEMAPHORE_FAILED()
#endif

#ifndef traceQUEUE_SEND
	#define traceQUEUE_SEND( pxQueue )
#endif

#ifndef traceQUEUE_SEND_FAILED
	#define traceQUEUE_SEND_FAILED( pxQueue )
#endif

#ifndef traceQUEUE_RECEIVE
	#define traceQUEUE_RECEIVE( pxQueue )
#endif

#ifndef traceQUEUE_PEEK
	#define traceQUEUE_PEEK( pxQueue )
#endif

#ifndef traceQUEUE_PEEK_FROM_ISR
	#define traceQUEUE_PEEK_FROM_ISR( pxQueue )
#endif

#ifndef traceQUEUE_RECEIVE_FAILED
	#define traceQUEUE_RECEIVE_FAILED( pxQueue )
#endif

#ifndef traceQUEUE_SEND_FROM_ISR
	#define traceQUEUE_SEND_FROM_ISR( pxQueue )
#endif

#ifndef traceQUEUE_SEND_FROM_ISR_FAILED
	#define traceQUEUE_SEND_FROM_ISR_FAILED( pxQueue )
#endif

#ifndef traceQUEUE_RECEIVE_FROM_ISR
	#define traceQUEUE_RECEIVE_FROM_ISR( pxQueue )
#endif

#ifndef traceQUEUE_RECEIVE_FROM_ISR_FAILED
	#define traceQUEUE_RECEIVE_FROM_ISR_FAILED( pxQueue )
#endif

#ifndef traceQUEUE_PEEK_FROM_ISR_FAILED
	#define traceQUEUE_PEEK_FROM_ISR_FAILED( pxQueue )
#endif

#ifndef traceQUEUE_DELETE
	#define traceQUEUE_DELETE( pxQueue )
#endif

#ifndef traceTASK_CREATE
	#define traceTASK_CREATE( pxNewTCB )
#endif

#ifndef traceTASK_CREATE_FAILED
	#define traceTASK_CREATE_FAILED()
#endif

#ifndef traceTASK_DELETE
	#define traceTASK_DELETE( pxTaskToDelete )
#endif

#ifndef traceTASK_DELAY_UNTIL
	#define traceTASK_DELAY_UNTIL()
#endif

#ifndef traceTASK_DELAY
	#define traceTASK_DELAY()
#endif

#ifndef traceTASK_PRIORITY_SET
	#define traceTASK_PRIORITY_SET( pxTask, uxNewPriority )
#endif

#ifndef traceTASK_SUSPEND
	#define traceTASK_SUSPEND( pxTaskToSuspend )
#endif

#ifndef traceTASK_RESUME
	#define traceTASK_RESUME( pxTaskToResume )
#endif

#ifndef traceTASK_RESUME_FROM_ISR
	#define traceTASK_RESUME_FROM_ISR( pxTaskToResume )
#endif

#ifndef traceTASK_INCREMENT_TICK
	#define traceTASK_INCREMENT_TICK( xTickCount )
#endif

#ifndef traceTIMER_CREATE
	#define traceTIMER_CREATE( pxNewTimer )
#endif

#ifndef traceTIMER_CREATE_FAILED
	#define traceTIMER_CREATE_FAILED()
#endif

#ifndef traceTIMER_COMMAND_SEND
	#define traceTIMER_COMMAND_SEND( xTimer, xMessageID, xMessageValueValue, xReturn )
#endif

#ifndef traceTIMER_EXPIRED
	#define traceTIMER_EXPIRED( pxTimer )
#endif

#ifndef traceTIMER_COMMAND_RECEIVED
	#define traceTIMER_COMMAND_RECEIVED( pxTimer, xMessageID, xMessageValue )
#endif

#ifndef traceMALLOC
    #define traceMALLOC( pvAddress, uiSize )
#endif

#ifndef traceFREE
    #define traceFREE( pvAddress, uiSize )
#endif

#ifndef traceEVENT_GROUP_CREATE
	#define traceEVENT_GROUP_CREATE( xEventGroup )
#endif

#ifndef traceEVENT_GROUP_CREATE_FAILED
	#define traceEVENT_GROUP_CREATE_FAILED()
#endif

#ifndef traceEVENT_GROUP_SYNC_BLOCK
	#define traceEVENT_GROUP_SYNC_BLOCK( xEventGroup, uxBitsToSet, uxBitsToWaitFor )
#endif

#ifndef traceEVENT_GROUP_SYNC_END
	#define traceEVENT_GROUP_SYNC_END( xEventGroup, uxBitsToSet, uxBitsToWaitFor, xTimeoutOccurred ) ( void ) xTimeoutOccurred
#endif

#ifndef traceEVENT_GROUP_WAIT_BITS_BLOCK
	#define traceEVENT_GROUP_WAIT_BITS_BLOCK( xEventGroup, uxBitsToWaitFor )
#endif

#ifndef traceEVENT_GROUP_WAIT_BITS_END
	#define traceEVENT_GROUP_WAIT_BITS_END( xEventGroup, uxBitsToWaitFor, xTimeoutOccurred ) ( void ) xTimeoutOccurred
#endif

#ifndef traceEVENT_GROUP_CLEAR_BITS
	#define traceEVENT_GROUP_CLEAR_BITS( xEventGroup, uxBitsToClear )
#endif

#ifndef traceEVENT_GROUP_CLEAR_BITS_FROM_ISR
	#define traceEVENT_GROUP_CLEAR_BITS_FROM_ISR( xEventGroup, uxBitsToClear )
#endif

#ifndef traceEVENT_GROUP_SET_BITS
	#define traceEVENT_GROUP_SET_BITS( xEventGroup, uxBitsToSet )
#endif

#ifndef traceEVENT_GROUP_SET_BITS_FROM_ISR
	#define traceEVENT_GROUP_SET_BITS_FROM_ISR( xEventGroup, uxBitsToSet )
#endif

#ifndef traceEVENT_GROUP_DELETE
	#define traceEVENT_GROUP_DELETE( xEventGroup )
#endif

#ifndef tracePEND_FUNC_CALL
	#define tracePEND_FUNC_CALL(xFunctionToPend, pvParameter1, ulParameter2, ret)
#endif

#ifndef tracePEND_FUNC_CALL_FROM_ISR
	#define tracePEND_FUNC_CALL_FROM_ISR(xFunctionToPend, pvParameter1, ulParameter2, ret)
#endif

#ifndef traceQUEUE_REGISTRY_ADD
	#define traceQUEUE_REGISTRY_ADD(xQueue, pcQueueName)
#endif

#ifndef traceTASK_NOTIFY_TAKE_BLOCK
	#define traceTASK_NOTIFY_TAKE_BLOCK()
#endif

#ifndef traceTASK_NOTIFY_TAKE
	#define traceTASK_NOTIFY_TAKE()
#endif

#ifndef traceTASK_NOTIFY_WAIT_BLOCK
	#define traceTASK_NOTIFY_WAIT_BLOCK()
#endif

#ifndef traceTASK_NOTIFY_WAIT
	#define traceTASK_NOTIFY_WAIT()
#endif

#ifndef traceTASK_NOTIFY
	#define traceTASK_NOTIFY()
#endif

#ifndef traceTASK_NOTIFY_FROM_ISR
	#define traceTASK_NOTIFY_FROM_ISR()
#endif

#ifndef traceTASK_NOTIFY_GIVE_FROM_ISR
	#define traceTASK_NOTIFY_GIVE_FROM_ISR()
#endif

#ifndef CONFIG_GENERATE_RUN_TIME_STATS
	#define CONFIG_GENERATE_RUN_TIME_STATS 0
#endif

#if ( CONFIG_GENERATE_RUN_TIME_STATS == 1 )

	#ifndef portCONFIGURE_TIMER_FOR_RUN_TIME_STATS
		#error If CONFIG_GENERATE_RUN_TIME_STATS is defined then portCONFIGURE_TIMER_FOR_RUN_TIME_STATS must also be defined.  portCONFIGURE_TIMER_FOR_RUN_TIME_STATS should call a port layer function to setup a peripheral timer/counter that can then be used as the run time counter time base.
	#endif /* portCONFIGURE_TIMER_FOR_RUN_TIME_STATS */

	#ifndef portGET_RUN_TIME_COUNTER_VALUE
		#ifndef portALT_GET_RUN_TIME_COUNTER_VALUE
			#error If CONFIG_GENERATE_RUN_TIME_STATS is defined then either portGET_RUN_TIME_COUNTER_VALUE or portALT_GET_RUN_TIME_COUNTER_VALUE must also be defined.  See the examples provided and the FreeRTOS web site for more information.
		#endif /* portALT_GET_RUN_TIME_COUNTER_VALUE */
	#endif /* portGET_RUN_TIME_COUNTER_VALUE */

#endif /* CONFIG_GENERATE_RUN_TIME_STATS */

#ifndef portCONFIGURE_TIMER_FOR_RUN_TIME_STATS
	#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS()
#endif

#ifndef CONFIG_USE_MALLOC_FAILED_HOOK
	#define CONFIG_USE_MALLOC_FAILED_HOOK 0
#endif

#ifndef portPRIVILEGE_BIT
	#define portPRIVILEGE_BIT ( ( UBaseType_t ) 0x00 )
#endif

#ifndef portYIELD_WITHIN_API
	#define portYIELD_WITHIN_API portYIELD
#endif

#ifndef pvPortMallocAligned
	#define pvPortMallocAligned( x, puxStackBuffer ) ( ( ( puxStackBuffer ) == NULL ) ? ( pvPortMalloc( ( x ) ) ) : ( puxStackBuffer ) )
#endif

#ifndef vPortFreeAligned
	#define vPortFreeAligned( pvBlockToFree ) vPortFree( pvBlockToFree )
#endif

#ifndef portSUPPRESS_TICKS_AND_SLEEP
	#define portSUPPRESS_TICKS_AND_SLEEP( xExpectedIdleTime )
#endif

#ifndef CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP
	#define CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP 2
#endif

#if CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP < 2
	#error CONFIG_EXPECTED_IDLE_TIME_BEFORE_SLEEP must not be less than 2
#endif

#ifndef CONFIG_USE_TICKLESS_IDLE
	#define CONFIG_USE_TICKLESS_IDLE 0
#endif

#ifndef CONFIG_PRE_SLEEP_PROCESSING
	#define CONFIG_PRE_SLEEP_PROCESSING( x )
#endif

#ifndef CONFIG_POST_SLEEP_PROCESSING
	#define CONFIG_POST_SLEEP_PROCESSING( x )
#endif

#ifndef CONFIG_USE_QUEUE_SETS
	#define CONFIG_USE_QUEUE_SETS 0
#endif

#ifndef portTASK_USES_FLOATING_POINT
	#define portTASK_USES_FLOATING_POINT()
#endif

#ifndef CONFIG_USE_TIME_SLICING
	#define CONFIG_USE_TIME_SLICING 1
#endif

#ifndef CONFIG_CONFIG_INCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS
	#define CONFIG_CONFIG_INCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0
#endif

#ifndef CONFIG_USE_NEWLIB_REENTRANT
	#define CONFIG_USE_NEWLIB_REENTRANT 0
#endif

#ifndef CONFIG_USE_STATS_FORMATTING_FUNCTIONS
	#define CONFIG_USE_STATS_FORMATTING_FUNCTIONS 0
#endif

#ifndef portASSERT_IF_INTERRUPT_PRIORITY_INVALID
	#define portASSERT_IF_INTERRUPT_PRIORITY_INVALID()
#endif

#ifndef CONFIG_USE_TRACE_FACILITY
	#define CONFIG_USE_TRACE_FACILITY 0
#endif

#ifndef mtCOVERAGE_TEST_MARKER
	#define mtCOVERAGE_TEST_MARKER()
#endif

#ifndef mtCOVERAGE_TEST_DELAY
	#define mtCOVERAGE_TEST_DELAY()
#endif

#ifndef portASSERT_IF_IN_ISR
	#define portASSERT_IF_IN_ISR()
#endif

#ifndef CONFIG_USE_PORT_OPTIMISED_TASK_SELECTION
	#define CONFIG_USE_PORT_OPTIMISED_TASK_SELECTION 0
#endif

#ifndef CONFIG_APPLICATION_ALLOCATED_HEAP
	#define CONFIG_APPLICATION_ALLOCATED_HEAP 0
#endif

#ifndef CONFIG_USE_TASK_NOTIFICATIONS
	#define CONFIG_USE_TASK_NOTIFICATIONS 1
#endif

#ifndef portTICK_TYPE_IS_ATOMIC
	#define portTICK_TYPE_IS_ATOMIC 0
#endif

#if( portTICK_TYPE_IS_ATOMIC == 0 )
	/* Either variables of tick type cannot be read atomically, or
	portTICK_TYPE_IS_ATOMIC was not set - map the critical sections used when
	the tick count is returned to the standard critical section macros. */
	#define portTICK_TYPE_ENTER_CRITICAL() portENTER_CRITICAL()
	#define portTICK_TYPE_EXIT_CRITICAL() portEXIT_CRITICAL()
	#define portTICK_TYPE_SET_INTERRUPT_MASK_FROM_ISR() portSET_INTERRUPT_MASK_FROM_ISR()
	#define portTICK_TYPE_CLEAR_INTERRUPT_MASK_FROM_ISR( x ) portCLEAR_INTERRUPT_MASK_FROM_ISR( ( x ) )
#else
	/* The tick type can be read atomically, so critical sections used when the
	tick count is returned can be defined away. */
	#define portTICK_TYPE_ENTER_CRITICAL()
	#define portTICK_TYPE_EXIT_CRITICAL()
	#define portTICK_TYPE_SET_INTERRUPT_MASK_FROM_ISR() 0
	#define portTICK_TYPE_CLEAR_INTERRUPT_MASK_FROM_ISR( x ) ( void ) x
#endif

/* Definitions to allow backward compatibility with FreeRTOS versions prior to
V8 if desired. */
#ifndef CONFIG_ENABLE_BACKWARD_COMPATIBILITY
	#define CONFIG_ENABLE_BACKWARD_COMPATIBILITY 1
#endif

#if CONFIG_ENABLE_BACKWARD_COMPATIBILITY == 1
	#define eTaskStateGet eTaskGetState
	#define portTickType TickType_t
	#define xTaskHandle TaskHandle_t
	#define xQueueHandle QueueHandle_t
	#define xSemaphoreHandle SemaphoreHandle_t
	#define xQueueSetHandle QueueSetHandle_t
	#define xQueueSetMemberHandle QueueSetMemberHandle_t
	#define xTimeOutType TimeOut_t
	#define xMemoryRegion MemoryRegion_t
	#define xTaskParameters TaskParameters_t
	#define xTaskStatusType	TaskStatus_t
	#define xTimerHandle TimerHandle_t
	#define xCoRoutineHandle CoRoutineHandle_t
	#define pdTASK_HOOK_CODE TaskHookFunction_t
	#define portTICK_RATE_MS portTICK_PERIOD_MS

	/* Backward compatibility within the scheduler code only - these definitions
	are not really required but are included for completeness. */
	#define tmrTIMER_CALLBACK TimerCallbackFunction_t
	#define pdTASK_CODE TaskFunction_t
	#define xListItem ListItem_t
	#define xList List_t
#endif /* CONFIG_ENABLE_BACKWARD_COMPATIBILITY */

/* Set CONFIG_USE_TASK_FPU_SUPPORT to 0 to omit floating point support even
if floating point hardware is otherwise supported by the FreeRTOS port in use.
This constant is not supported by all FreeRTOS ports that include floating 
point support. */
#ifndef CONFIG_USE_TASK_FPU_SUPPORT
	#define CONFIG_USE_TASK_FPU_SUPPORT 1
#endif

#ifdef __cplusplus
}
#endif

#endif /* INC_FREERTOS_H */

