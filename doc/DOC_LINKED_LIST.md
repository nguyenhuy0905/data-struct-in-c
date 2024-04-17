# Linked list
### Overview
- A singly-linked list
---
### Methods
- `linked_list_new()`
    - Initialize a new instance of type `linked-list` 
    - Return:
        - The pointer to the newly created instance of `linked-list`
    - Possible errors:
        - **ENOMEM**: memory allocation error, possibly due to the system running out of memory. 
    - Usage note:
        - Be sure NOT to use `linked_list_new()` on an already initialized `linked-list` pointer. Doing so results in loss of memory address of the previous `linked-list` instance, causing a memory leak. 
        - If you need to reuse a pointer, be sure either:
            1. The pointer is pointing to `NULL`
            2. There is another pointer holding reference to that memory address.
    - Detailed descriptions
        - This method does the following sequentially:
            - Allocate memory to the new `linked-list` instance
            - Check whether memory allocation was successful
                - If not, throw **ENOMEM**
            - Check whether `node` `_before_head` exists; if not, initialize that `node`:
                - `_before_head` is simply a dummy `node` that points to `head` of the relevant `linked-list` used in methods that may need access to the head of any `linked-list`.
                - Such methods include `linked_list_insert` or `linked_list_start_iteration`
            - Assign some default values to the newly created `linked-list`. These include:
                - `head` and `tail` to `NULL`
                - `length` to 0
                - `iter` (shorthand for `linked_list_iterator`) to `NULL`
---
- `linked_list_free(linked_list *self)`
    - Destruct the `linked-list` passed in, alongside all `node`s it contains
    - Parameters:
        - `self`: the `linked-list` instance to be freed
    - Possible errors:
        - **EFAULT**: `self` is `NULL`
    - Detailed descriptions
        - This method does the following sequentially:
            - Check whether `self` is `NULL`
                - If yes, throw **EFAULT** and exit
                - Otherwise, proceed
            - Free each `node` contained by the `linked-list`, starting from the `head`, then assign each of them to `NULL`
            - Free `_before_head` and set it to `NULL`
            - Finally free `self` and set `self` to `NULL`
---
