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
- Compile a test executable: __COMING SOON__
- Run a test executable: __COMING SOON__
- For now you can manually do like so:
```
# make sure you're at the directory of the Makefile
# for example,
clang -o ./bin/obj/libtest-linked-list.so -shared -fPIC --debug ./test/test-linked-list.c #you can add -O0 flag to prevent the compiler from doing sus
clang -o ./bin/test -I./src/header/ -L./lib/ -L./bin/obj/ -llinked-list -ltest-linked-list --debug 
LD_LIBRARY_PATH=./lib/:./bin/obj/ ./bin/test
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
- [ ] Write `MakeTest.mk` to compile test files into executables
- [ ] Modify the original `Makefile` to account for the `MakeTest.mk` file
- [ ] Implement stack and queue
- [ ] Implement binary tree
- [ ] Implement AVL tree
- [ ] Implement red-black tree (not guaranteed I would do though)
- [ ] Implement a simple hash map
- [ ] Implement graph
