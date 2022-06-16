#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This file supports building for native or target systems.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      compile-all - All files in project compiled, but not linked.
#      <filename>.o - Assembled version of input file.
#      <filename>.asm - Compiled version of input file.
#      <filename>.i - Preprocessed version of input file.
#
# Platform Overrides:
# 	PLATFORM - Target platform (HOST, MSP432)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#Common
BASENAME = c1m2
TARGET = $(BASENAME).out
MAPFILE = $(BASENAME).map
CPPFLAGS = -Wall \
	   -Werror \
	   -std=c99 \
	   $(INCLUDES)
OBJS = $(SOURCES:.c=.o)

# MSP432 Specific
ifeq ($(PLATFORM),MSP432)
   # Architectures Specific Flags
#   LINKER_FILE = ../msp432p401r.lds
   CPU =cortex-m4
   ARCH =thumb
   SPECS =nosys.specs
   
   # Compiler Flags and Defines
   CPP = arm-none-eabi-cpp
   CC = arm-none-eabi-gcc
   AS = arm-none-eabi-as
#   LD = arm-none-eabi-ld
#   LDFLAGS = -T $(LINKER_FILE) \
             -Wl,$(MAPFILE)
   CFLAGS = -mcpu=$(CPU) \
            -m$(ARCH) \
            -march=armv7e-m \
            -mfloat-abi=hard \
            -mfpu=fpv4-sp-d16 \
            --specs=$(SPECS) \
            -DMSP432 \
            -O0 \
            -g
# Host Specific
else
   # Compiler Flags and Defines
   CPP = cpp
   CC = gcc
   AS = as
#   LD = ld
#   LDFLAGS = -Wl,$(MAPFILE)
   CFLAGS = -DHOST \
            -O0 \
            -g
endif

# Overwrite GNU Make Built-in rule
%.o : %.c

# Assemble Individual Files
# Same functionality as: gcc -c $(CFLAGS) $(CPPFLAGS) %.c -o %.o
%.o : %.asm
	$(AS) $< -o $@

# Compile Individual Files
%.asm : %.i
	$(CC) -S $(CFLAGS) $< -o $@

# Preprocess Individual Files
# Same functionality as: gcc -E $(CFLAGS) $(CPPFLAGS) %.c -o %.i
%.i : %.c
	$(CPP) $(CPPFLAGS) $(CFLAGS) $< -o $@

#.PHONY: compile-all
#compile-all : $(OBJS) 

#$(TARGET): compile-all
#	$(LD) $(LDFLAGS) $^ -o $@

#.PHONY: build
#build: $(TARGET)

#$(BASENAME).asm : $(TARGET)
#	objdump $<

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(MAPFILE) *.i *.asm
