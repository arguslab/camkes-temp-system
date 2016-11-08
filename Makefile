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
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/arch/${ARCH}/*.c))

Alarm_ASMFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/crt/arch-${ARCH}/crt0.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/arch/${ARCH}/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Alarm/src/plat/${PLAT}/*.S))

Controller_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/arch/${ARCH}/*.c))

Controller_ASMFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/crt/arch-${ARCH}/crt0.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/arch/${ARCH}/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Controller/src/plat/${PLAT}/*.S))

Heater_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/arch/${ARCH}/*.c))

Heater_ASMFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/crt/arch-${ARCH}/crt0.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/arch/${ARCH}/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Heater/src/plat/${PLAT}/*.S))

Sensor_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/arch/${ARCH}/*.c))

Sensor_ASMFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/crt/arch-${ARCH}/crt0.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/arch/${ARCH}/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Sensor/src/plat/${PLAT}/*.S))

Timer_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/arch/${ARCH}/*.c))

Timer_ASMFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/crt/arch-${ARCH}/crt0.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/arch/${ARCH}/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Timer/src/plat/${PLAT}/*.S))

Webserver_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/plat/${PLAT}/*.c)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/arch/${ARCH}/*.c))

Webserver_ASMFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/crt/arch-${ARCH}/crt0.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/arch/${ARCH}/*.S)) \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/Webserver/src/plat/${PLAT}/*.S))



include ${PWD}/tools/camkes/camkes.mk
