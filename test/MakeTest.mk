CC := clang
MODE := --debug

# test file
SRCS := $(wildcard ./test-*.c)
OBJS := $(patsubst ./%.c, ../bin/%, $(SRCS))

all: export LD_LIBRARY_PATH := ${LD_LIBRARY_PATH}:./simple-utest/:../lib/
all: $(OBJS)
	../bin/test-linked-list

$(OBJS): ../bin/%: ./%.c
	$(CC) -o $@ $^ -L./simple-utest/ -lsimple-utest -L../lib/ -llinked-list $(MODE)
