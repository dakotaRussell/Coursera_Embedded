# File paths.
SOURCEDIR := $(PROJDIR)/src
INCLUDEDIR := $(PROJDIR)/include
BUILDDIR := $(PROJDIR)/build
BINDIR := $(BUILDDIR)/bin
OBJDIR := $(BUILDDIR)/objs
DEPDIR := $(BUILDDIR)/deps

INCLUDES = $(addprefix -I ,$(INCLUDEDIR))
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)
DEPS = $(SOURCES:%.c=$(DEPDIR)/%.d)

CPPFLAGS += \
	   $(INCLUDES)

#.PHONY: echo
#echo:
#	@for file in $(SOURCES) ; do \
#	  echo $(SOURCEDIR)/$$file ; \
#	done
#	@for obj in $(OBJECTS) ; do \
#	  echo $$obj ; \
#	done
#	@for dep in $(DEPS) ; do \
#	  echo $$dep ; \
#	done
#	@echo $(INCLUDES)

.PHONY: $(BINDIR)
$(BINDIR): $(OBJECTS)
	mkdir -p $(BINDIR)
	cp $^ $(BINDIR)
	@#$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SOURCEDIR)/%.c
	mkdir -p $(DEPDIR)
	mkdir -p $(OBJDIR)
	$(CC) -c $(DEPFLAGS) $(DEPDIR)/$(basename $(notdir $@)).d \
	$(CPPFLAGS) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -r -f $(OBJDIR) $(DEPDIR) $(BINDIR)
