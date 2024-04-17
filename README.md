> Disclaimer: FOR PERSONAL USE. Well actually, what use do I even have with this, other than playing around?
>Anyways, this is my attempt to write data structures in C. 
### Dependencies
- `clang`. 
- If you don't have `clang` installed, you can use `gcc` instead. Edit the `Makefile` and `test/MakeTest.mk` file's `CC` variable to `gcc`
 ### Why not C++?
 - I don't know C++. And besides, C++ is already designed for this kind of stuff. How about we try something more,
difficult? To be fair, I think C is actually simpler.

### NOTE:
- The data structures ONLY stores integers. This is to ensure caching is working properly. 
- I may be overly wary about performance though.

### How to use this?
```
git clone https://github.com/nguyenhuy0905/data-struct-in-c.git
cd ./data-struct-in-c
# add the necessary directories first, then compile the source code into shared libraries-c
make setup && make 
```
- Compile and run a test executable:
```
# make sure you're at the directory of the Makefile
make test TEST=[data-structure-to-test]
# so, to run a test on linked list, for example
make test TEST=linked-list
```
- If you want to debug with GDB:
    - Ensure _all_ object files (including the libraries) are compiled with debug flags (by setting the `MODE` variable in the `Makefile` and `./test/MakeTest.mk` file to `--debug`)
    - Compile and run a test executable first with the commands above
    - Ensure you're at the directory of the `Makefile`
    - Run the following:
    ```
    LD_LIBRARY_PATH=./lib/ gdb ./bin/[test-data-structure]
    ```
### Writing a test file
- To automate the process, please follow the following rules:
    - Put the test file inside the `test` directory
    - Name it as `test-[data-structure-to-test].c`
    - So, for example, to test the linked list, name as `test-linked-list.c`
    - Write the file with at least the following:
    ```
    #include "../src/header/[data-structure-to-test].h"
    #include <stdlib.h>

    int main(int argc, char *argv[]){
        // your tests go here

        return EXIT_SUCCESS;
    }
    ```
### What have you written?

### What are you planning to write?
- Resizable array.
- Stack, priority queue (which basically are linked list)
- Hash (map, set)
- Tree (BST, Red-Black)
- Heap (maybe)
- Graph (undirected, directed, unweighted, weighted)

### NOTE
- Second attempt, after I have learned, stuff.
---
### PLANS
- [ ] Implement linked list **on the way**
- [x] Write `MakeTest.mk` to compile test files into executables
- [x] Modify the original `Makefile` to account for the `MakeTest.mk` file
- [ ] Implement stack and queue
- [ ] Implement binary tree
- [ ] Implement AVL tree
- [ ] Implement red-black tree (not guaranteed I would do though)
- [ ] Implement a simple hash map
- [ ] Implement graph
