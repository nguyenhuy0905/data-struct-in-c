CC := clang
DEBUG := -O0 --debug
PROD := -O2

SRC := src
TEST := test
LIB := lib
HEADER := src/header
OBJ := bin/obj
BIN := bin

SRC_FILES := $(wildcard src/*.c)
LDD_FILES := $(patsubst $(SRC)/%.c,$(LIB)/lib%.so,$(SRC_FILES))

OPTS := -Wno-unused-command-line-argument

all: $(LDD_FILES)

$(LDD_FILES): $(LIB)/lib%.so: $(SRC)/%.c
	$(CC) -o $@ $< -fpic -shared

.PHONY: test

TEST_FILE ?=
test:
	make -f test/Makefile $(TEST_FILE)

.PHONY: var-test
# use this to check if my Makefile is doing alright
var-test:
	@echo "Compiler is $(CC)"
	@echo "Sources: $(SRC_FILES)"
	@echo "Shared objects: $(LDD_FILES)"

.PHONY: clean

clean:
	rm -f $(LDD_FILES)
