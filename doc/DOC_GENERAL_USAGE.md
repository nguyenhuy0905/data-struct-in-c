# GENERAL USAGE
### Initialization and free
- Do NOT use `malloc` and cast to initialize data structures yourself, instead use the dedicated `[data_structure_name]_new` function.
    - Eg, for `linked-list`, use `linked_list_new`.
    - In this case, the `init` function also initialize some default values for the variables contained inside the `linked-list`
- Do NOT free the data structure using the normal `free` function. Use the dedicated `[data_structure_name]_free` function.
    - Eg, for `linked-list`, use `linked_list_free`. 
    - In this case, the `linked_list_free` function also frees all the nodes contained inside the linked list.
- To loop through a collection, the easiest way is to use the dedicated `iterator`
    - Eg, for `linked-list`, call `linked_list_start_iteration` to start the iteration.
    - Then, the first call of `linked_list_iteration_next` gives back the iterator if there's still data to loop through, and writes the first value to the variable passed in.
    - If you loop to the end, `linked_list_iteration_next` will terminate itself with `linked_list_end_iteration`.
    - But if you didn't, you should manually call `linked_list_end_iteration`.
    - Do note that this means you can only loop through the collection once at a time.
