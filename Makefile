obj-y += tasks.o list.o queue.o 
obj-$(CONFIG_SUPPORT_DYNAMIC_ALLOCATION) += heap/
obj-$(CONFIG_SUPPORT_STATIC_ALLOCATION) += static.o
obj-$(CONFIG_USE_TIMERS) += timers.o
obj-$(CONFIG_USE_CO_ROUTINES) += croutine.o
obj-$(CONFIG_EVENT_GROUP) += event_groups.o
obj-$(CONFIG_DEFAULT_TASK_RETURN_ADDRESS) += taskReturn.o
ldflags-y=-T freertos/freertos.ld
