# DOCUMENTATION
### Menu
1. [Linked list](./DOC_LINKED_LIST.md)
### Disclaimer
- For performance, I will just write these data structures, allowing only `int`s to be stored inside.
- I could have used `void*` but `void*` means you can throw ANY data types in, and it is still valid. Which is not the behavior desired.
- Or am I a little too wary?
- Anyways, if you want any of the data structure to store different types of data, you will need to:
    - Take the source file at `src`
    - Modify it.
        - Currently, I haven't plans to implement data structures for pointer types (eg, strings) yet. You can modify a source file's data type, so long as the data type is not a pointer, there will not be much code to change, hopefully.
