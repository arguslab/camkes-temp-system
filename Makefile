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

AlarmProcess_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/AlarmProcess/src/*.c))

AlarmProcess_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/AlarmProcess/include/*.h))


TempControlProcess_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/TempControlProcess/src/*.c))

TempControlProcess_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/TempControlProcess/include/*.h))


FanProcess_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/FanProcess/src/*.c))

FanProcess_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/FanProcess/include/*.h))


TempSensorProcess_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/TempSensorProcess/src/*.c))

TempSensorProcess_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/TempSensorProcess/include/*.h))


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


WebInterface_CFILES := \
    $(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/WebInterface/src/*.c))

WebInterface_HFILES := \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/common/*.h)) \
	$(patsubst ${SOURCE_DIR}/%,%,$(wildcard ${SOURCE_DIR}/components/WebInterface/include/*.h))


include ${PWD}/tools/camkes/camkes.mk
