CC := clang

# files
TEST_SRCS := $(wildcard ./*.c)
# flags
FLAGS := -L./lib -lds-in-c -L./simple-utest-0.4/ -lsimple-utest
TEST_OBJS := $(patsubst ./%.c,./obj/%.o,$(TEST_SRCS))
TEST_EXEC := ./test

all: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJS)
	$(CC) $(FLAGS) -o $@ $^

$(TEST_OBJS): ./obj/%.o: ./%.c
	$(CC) -c -o $@ $^

.PHONY: run

run: export LD_LIBRARY_PATH := ./lib:./simple-utest-0.4/
run: $(TEST_EXEC)
	./$^

.PHONY: clean

clean:
	rm -f $(TEST_EXEC) $(TEST_OBJS)
