CC := clang

# files
SRCS := $(wildcard ./src/*.c)
OBJS := $(patsubst ./src/%.c,./build/obj/%.o,$(SRCS))
LIB := ./build/libds-in-c.so # if you only want to link 1 library

# options
LIB_FLAGS := -fPIC -shared -fms-extensions -Wall -Wno-microsoft-anon-tag
OBJ_FLAGS := -c -fPIC -fms-extensions -Wall -Wno-microsoft-anon-tag

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(LIB_FLAGS) -o $@ $^

$(OBJS): ./build/obj/%.o: ./src/%.c
	$(CC) $(OBJ_FLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(LIB) $(OBJS)
	cd ./test && make -f ./Maketest.mk clean

.PHONY: test

test: $(LIB)
	cd ./test && make -f ./Maketest.mk run
