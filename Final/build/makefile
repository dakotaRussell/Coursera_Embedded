# File paths.
BASE := final_program
PROJDIR := $(realpath $(CURDIR))
BINDIR := $(PROJDIR)/bin
TARGET := $(BINDIR)/$(BASE).exe
MAPFILE := $(BINDIR)/$(BASE).map

# Common libraries.
LIBS_TO_BUILD := ../common/build
LIBS := $(realpath $(PROJDIR)/..)/common/build/bin 

# Flags.
CC := gcc
CPPFLAGS := -Wall \
           -Werror \
           -std=c99
CFLAGS := -O0 \
          -g \
          -DCOURSE1 \
	  -DVERBOSE
DEPFLAGS := -MMD \
           -MF
LDFLAGS = -Map=$(MAPFILE)

# Platform specific arguements.
ifeq ($(PLATFORM),MSP432)
  MSP432_LIB = $(PROJDIR)/../msp432/build
  LIBS_TO_BUILD += $(MSP432_LIB)
  LINKER_FILE = msp432p401r.lds
  CPU =cortex-m4
  ARCH =thumb
  SPECS =nosys.specs
  CC = arm-none-eabi-gcc
  LDFLAGS += \
            -T $(LINKER_FILE)
  CFLAGS += \
            -mcpu=$(CPU) \
      	    -m$(ARCH) \
            -march=armv7e-m \
	    -mfloat-abi=hard \
	    -mfpu=fpv4-sp-d16 \
	    --specs=$(SPECS) \
	    -DMSP432
else
  CFLAGS += \
            -DHOST
endif

export CC CPPFLAGS CFLAGS DEPFLAGS

# Build targets.
.PHONY: all
all: $(LIBS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -Wl,$(LDFLAGS) $(wildcard $(BINDIR)/*.o) \
	-o $(TARGET)

$(LIBS) : $(LIBS_TO_BUILD) 
	$(MAKE) --directory=$^ $@
	mkdir -p $(BINDIR)
	cp -r $@/*.o $(BINDIR)

.PHONY: clean
clean: $(LIBS_TO_BUILD)
	$(MAKE) --directory=$^ $@
	rm -r -f $(BINDIR)

