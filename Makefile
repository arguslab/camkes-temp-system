#
# Copyright 2014, NICTA
#
# This software may be distributed and modified according to the terms of
# the BSD 2-Clause license. Note that NO WARRANTY is provided.
# See "LICENSE_BSD2.txt" for details.
#
# @TAG(NICTA_BSD)
#

TARGETS := $(notdir ${SOURCE_DIR}).cdl
ADL := temp_system.camkes

Alarm_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/*.c))

Alarm_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/include/*.h))


Controller_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/*.c))

Controller_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/include/*.h))


Heater_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/*.c))

Heater_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/include/*.h))


Sensor_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/*.c))

Sensor_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/include/*.h))


SoC_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/SoC/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/SoC/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/SoC/src/arch/${ARCH}/*.c))

SoC_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/SoC/include/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/SoC/include/plat/${PLAT}/*.h)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/SoC/include/arch/${ARCH}/*.h))


Timer_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/arch/${ARCH}/*.c))

Timer_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/include/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/include/plat/${PLAT}/*.h)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/include/arch/${ARCH}/*.h))


Webserver_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/*.c))

Webserver_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/include/*.h))


include ${PWD}/tools/camkes/camkes.mk
