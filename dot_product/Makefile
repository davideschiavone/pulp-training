PULP_APP = test
PULP_APP_SRCS = main.c dotp.c

PULP_CFLAGS += -O3

#rv32imcxpulp dotp
PULP_ARCH_CFLAGS    =  -march=rv32imcxpulpv2
PULP_ARCH_LDFLAGS   =  -march=rv32imcxpulpv2
PULP_ARCH_OBJDFLAGS = -Mmarch=rv32imcxpulpv2
#PULP_ARCH_CFLAGS    +=  -DUSE_SIMD
#PULP_ARCH_CFLAGS    +=  -DUSE_LOOPUNROLLING

include $(PULPRT_HOME)/rules/pulp.mk