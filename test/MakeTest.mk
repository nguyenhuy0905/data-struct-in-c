CC := clang
MODE := --debug

# directories
LIB_DIR := ../lib/
OBJ_DIR := ../bin/obj/
BUILD_DIR := ../bin/
HEADER_DIR := ../src/header/

# binaries and source files
TEST_SRCS := $(wildcard ./test-*.c)
TEST_OBJS := $(patsubst ./%.c,$(OBJ_DIR)%.o,$(TEST_SRCS))
TEST_EXECS := $(patsubst $(OBJ_DIR)%.o,$(BUILD_DIR)%,$(TEST_OBJS))

TEST ?= linked-list
LIB_INCL := -l$(TEST)

all: run

run: $(BUILD_DIR)test-$(TEST)
	@echo "===== TEST ====="
	@echo ""
	$(BUILD_DIR)test-$(TEST)
	@echo ""
	@echo "===== TEST ====="

$(BUILD_DIR)test-$(TEST): ./test-$(TEST).c $(LIB_DIR)lib$(TEST).so
	$(CC) -o $@ $< -L$(LIB_DIR) $(LIB_INCL) -rpath $(LIB_DIR) $(MODE)

$(LIB_DIR)lib$(TEST).so:
	cd .. && make

.PHONY: check

check:
	@echo $(TEST_SRCS)
	@echo $(TEST_OBJS)
	@echo $(TEST_EXECS)
	@echo $(LD_LIB_PATH)
	@echo $(LIB_INCL)

.PHONY: clean

clean:
	rm -f $(TEST_OBJS) $(TEST_EXECS)
	rm -f $(wildcard $(OBJ_DIR)*)


