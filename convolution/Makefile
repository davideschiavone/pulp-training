
PULP_APP = convolution
PULP_APP_SRCS = convolution.c conv_kernels.c
PULP_CFLAGS = -O2 -g

#rv32imcxpulp dotp
#PULP_ARCH_CFLAGS    =  -march=rv32imcxpulpv2
#PULP_ARCH_LDFLAGS   =  -march=rv32imcxpulpv2
#PULP_ARCH_OBJDFLAGS = -Mmarch=rv32imcxpulpv2
#PULP_ARCH_CFLAGS    +=  -DPULP_EXT -DDOTP

#rv32imcxpulp
#PULP_ARCH_CFLAGS    =  -march=rv32imcxpulpv2
#PULP_ARCH_LDFLAGS   =  -march=rv32imcxpulpv2
#PULP_ARCH_OBJDFLAGS = -Mmarch=rv32imcxpulpv2
#PULP_ARCH_CFLAGS    +=  -DPULP_EXT

#rv32imc
PULP_ARCH_CFLAGS    =  -march=rv32imc -DRV_ISA_RV32
PULP_ARCH_LDFLAGS   =  -march=rv32imc
PULP_ARCH_OBJDFLAGS = -Mmarch=rv32imc


include $(PULPRT_HOME)/rules/pulp.mk
