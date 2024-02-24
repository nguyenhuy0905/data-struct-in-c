#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// @brief Represents a node in a singly linked list
typedef struct {
    void *next;
    char data[64];
} Node;
/// @brief header node
Node *head = NULL;
Node *pHead;

/// @brief a pointer to the head node. Useful in certain situations, like adding a node to the head
int list_length = 0;

/// @brief Add a node at the specified position
/// @param data the value that the node will contain
/// @param position where order of the node in the linked list
/// @return the node just added
Node *add_node(char data[64], int position){
    // allocate memo for a node and check whether the allocation fucks up
    Node *new = (Node*)malloc(sizeof(Node));

    // checking whether memory is correctly allocated
    if(new == NULL) {
        //printf("Error allocating memo\n");
        return NULL;
    }
    /*
    Note: new->data = data doesn't work. The text editor will shout at me.
    if input param is char *data (aka, modifiable), which itself is input_data
    in line 120, then every time input_data is changed, every-single-value in the
    list gets changed also.
    */
    strcpy(new->data, data);

    // if the linked list has nothing yet
    if(head == NULL){
        new->next = NULL; 
        head = new;

        pHead = (Node*)malloc(sizeof(Node));
        pHead->next = head;

        list_length++;
        //printf("Added new head\n");

        printf("Node with value \"%s\" has been added\n", data);
        return new;
    }

    if(position == 0){
        new->next = head;
        head = new;
        list_length++;
        pHead->next = head;
        //printf("Added new head again\n");
        printf("Node with value \"%s\" has been added\n", data);
        return new;
    }
    
    Node *current = pHead;
    int i;
    for(i = 0; i < position; i++) current = current->next;
    new->next = current->next;
    current->next = new;
    list_length++;
    //printf("Inserted new value\n");
    printf("Node with value \"%s\" has been added\n", data);
    return new;
}

/// @brief remove node at specified position
/// @param position the position to remove the node
void remove_node(int position){
    Node *remove_prev = pHead;
    Node *remove;
    // this will get the node BEFORE the node to be
    int i;
    for(i = 0; i < position; i++){
        remove_prev = remove_prev->next;
    }
    remove = remove_prev->next;
    remove_prev->next = remove->next;
    if(position == 0) head = remove_prev->next;
    printf("Successfully removed node at index %d\n", i);
    free(remove);
    return;
}

/// @brief print all the values, from head to tail, of the list
void print_list(){
    Node *curr = head;

    int i = 0;
    printf("The values currently stored in the linked list are:\n");
    while(curr != NULL){
        printf("%s->", curr->data);
        curr = curr->next;
        i++;
    }
    printf("NULL\n");
    printf("This list contains %d nodes\n", i);
    return;
}

/// @brief A list of input options corresponding to the print_options() function down here
enum user_input_option{
    ADD_NODE = 1,
    REMOVE_NODE = 2,
    PRINT_LIST = 3,
    QUIT_PROGRAM = 4
};

void print_options(){
    printf("Choose one of the following operations:\n");
    printf("[1] Add a node into the linked list\n");
    printf("[2] Remove a node from the linked list\n");
    printf("[3] Print out the current list\n");
    printf("[4] Quit the program\n");
}

/// @brief A list of action to be done after getting the position. Either add a node at that position, or remove one
enum position_action{
    REMOVE = 0,
    ADD = 1
};

/// @brief Give a prompt corresponding to action to be taken and record the user-input position
void get_position(int *position, int action){
    while(*position < 0 || *position > list_length){
        printf("Please input the position to %s: ", (action == 1) ? "add this node" : "remove a node");
        scanf(" %d", position);
        if(*position < 0 || *position > list_length){
            printf("Skillissue. Give a value again\n");
        }
    }
    return; 
}

void prompt_add(char input_data[], int *position){
    printf("Please input the value for the node (max length 64): ");
    scanf(" %[^\n]%*c", input_data);
    get_position(position, ADD);
    add_node(input_data, *position);
    *position = -1;
    return;
}

void prompt_remove(char input_data[], int *position){
    if(list_length == 0){
        printf("No item in list!\n");
        return;
    }
    get_position(position, REMOVE);
    remove_node(*position);
    *position = -1;
    return;
}

void get_user_input(int *input, char input_data[], int *position){
    print_options();
    scanf(" %d", input);

    switch(*input){
        case ADD_NODE:
            prompt_add(input_data, position);      
            break;
        case REMOVE_NODE:
            prompt_remove(input_data, position);            
            break;
        case PRINT_LIST:
            print_list();
            break;
        case QUIT_PROGRAM:
            return;
    }
}

int main(){
    int input = 1;    
    char input_data[64];
    int position = -1;

    while(input >= ADD_NODE && input < QUIT_PROGRAM){
        get_user_input(&input, input_data, &position); 
    }
    printf("Closing the program\n");
    free(pHead);
    return 0;
}