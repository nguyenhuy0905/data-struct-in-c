CC := clang
DEBUG := -O0 --debug
PROD := -O2
MODE := $(PROD)

SRCS := $(wildcard ./src/*.c)
LIBS := $(patsubst ./src/%.c,./lib/lib%.so,$(SRCS))
HEADER_INCL := -I./src/header/

LD_LIB_PATH := LD_LIBRARY_PATH="./lib"

all: $(LIBS)
	@echo $(SRCS)
	@echo $(LIBS)

$(LIBS): ./lib/lib%.so: ./src/%.c
	$(CC) -o $@ $< -shared -fPIC $(HEADER_INCL) $(MODE)

.PHONY: check

check:
	@echo $(SRCS)
	@echo $(LIBS)
