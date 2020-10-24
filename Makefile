obj-y += tasks.o list.o queue.o 
obj-$(CONFIG_SUPPORT_DYNAMIC_ALLOCATION) += heap/
obj-$(CONFIG_SUPPORT_STATIC_ALLOCATION) += static.o
obj-$(CONFIG_USE_TIMERS) += timers.o
obj-$(CONFIG_USE_CO_ROUTINES) += croutine.o
obj-$(CONFIG_EVENT_GROUP) += event_groups.o
obj-$(CONFIG_DEFAULT_TASK_RETURN_ADDRESS) += taskReturn.o
obj-$(CONFIG_STREAM_BUFFER) += stream_buffer.o
ldflags-y=-T freertos/freertos.ld

obj-$(CONFIG_GEN_VERSION) += version.o
BUILDID := $(USER)@$(shell hostname) $(shell date +'%Y-%m-%d %H:%M:%S')
$(obj)/version.c: FORCE
	@echo "  GEN     $(obj)/version.c"
	$(Q)version="const char *versionKernel = \""; \
	dir=`pwd`; \
	cd `dirname $@`; \
	version=$$version`git log -n 1 --pretty="format:$(BUILDID) %H" --no-notes`; \
	if git diff-index --name-only HEAD | grep -qv "^scripts/package" > /dev/null; then \
		version="$$version-dirty"; \
	fi; \
	cd $$dir; \
	version="$$version FreeRTOS Version: \" tskKERNEL_VERSION_NUMBER;"; \
	echo '#include <FreeRTOS.h>' > $@; \
	echo '#include <task.h>' >> $@; \
	echo $$version >> $@;
