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
#      c1m2.out - Final executable file.
#      build - Final executable file.
#      compile-all - All files in project compiled, but not linked.
#      c1m2.asm - Assembly of final executable.
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
DEPDIR := .deps
DEPFLAGS = -MT $@\
           -MMD \
	   -MP \
	   -MF $(DEPDIR)/$*.d
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:%.c=$(DEPDIR)/%.d)

# MSP432 Specific
ifeq ($(PLATFORM),MSP432)
   # Architectures Specific Flags
   LINKER_FILE = ../msp432p401r.lds
   CPU =cortex-m4
   ARCH =thumb
   SPECS =nosys.specs
   
   # Compiler Flags and Defines
   CPP = arm-none-eabi-cpp
   CC = arm-none-eabi-gcc
   AS = arm-none-eabi-as
   LD = arm-none-eabi-ld
   LDFLAGS = -Map=$(MAPFILE) \
             -T $(LINKER_FILE)
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
   LD = ld
   LDFLAGS = -Map=$(MAPFILE)
   CFLAGS = -DHOST \
            -O0 \
            -g
endif

.PHONY: build
build: $(TARGET)

# Assembly size of final executable.
$(BASENAME).asm : $(TARGET)
	objdump $<

# Link objects file into final executable.
$(TARGET): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -Wl,$(LDFLAGS) $^ -o $@

# Create dependency directory if it doesn't exist.
#$(DEPDIR): ;
#	@mkdir -p $@

# Create dependency file target.
#$(DEPS):

# This is more accurately described as assemble-all.
.PHONY: compile-all
compile-all : $(OBJS)

# Approach 1: Always starting from source.
# Assemble Individual Files
# Overwrite GNU Make Built-in rule
%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@
#%.o : %.c $(DEPDIR)/%.d | $(DEPDIR)
#	$(CC) -c $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS) $< -o $@

# Compile Individual Files
%.asm : %.c
	$(CC) -S $(CPPFLAGS) $(CFLAGS) $< -o $@

# Preprocess Individual Files
%.i : %.c
	$(CC) -E $(CPPFLAGS) $(CFLAGS) $< -o $@

# Approach 2: Chain the results from previous step as input to next step in build.
# Link objects file into final executable.
#$(TARGET): $(OBJS)
#	$(LD) $(LDFLAGS) $^ -o $@

# Assemble Individual Files
#%.o : %.asm
#	$(AS) $< -o $@
#
# Compile Individual Files
#%.asm : %.i
#	$(CC) -S $(CPPFLAGS) $(CFLAGS) $< -o $@
#
# Preprocess Individual Files
#%.i : %.c
#	$(CPP) $(CPPFLAGS) $(CFLAGS) $< -o $@
#
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(MAPFILE) *.i *.asm -r $(DEPDIR)

#include $(wildcard $(DEPS))
