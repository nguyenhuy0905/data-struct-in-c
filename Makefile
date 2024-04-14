CC := clang
DEBUG := -O0 --debug
PROD := -O2
MODE := $(PROD)

SRCS := $(wildcard ./src/*.c)
LIBS := $(patsubst ./src/%.c,./lib/lib%.so,$(SRCS))

LD_LIB_PATH := LD_LIBRARY_PATH="./lib"

all: $(LIBS)
	@echo $(SRCS)
	@echo $(LIBS)

$(LIBS): ./lib/lib%.so: ./src/%.c:
	$(CC) -o $@ $< -shared -fPIC -I./src/header/ $(MODE)

.PHONY: check

check:
	@echo $(SRCS)
	@echo $(LIBS)
