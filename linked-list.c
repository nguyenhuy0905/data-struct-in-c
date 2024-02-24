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

    if(new == NULL) {
        printf("Error allocating memo\n");
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
        printf("Added new head\n");
        return new;
    }

    if(position == 0){
        new->next = head;
        head = new;
        list_length++;
        pHead->next = head;
        printf("Added new head again\n");
        return new;
    }
    
    Node *current = pHead;
    int i;
    for(i = 0; i < position; i++) current = current->next;
    new->next = current->next;
    current->next = new;
    list_length++;
    printf("Inserted new value\n");
    return new;
}

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

int main(){
    int input = 1;    
    char input_data[64];
    int position = -1;

    while(input >= ADD_NODE && input < QUIT_PROGRAM){
        print_options();
        scanf(" %d", &input);
        switch(input){
            case ADD_NODE:
                
                printf("Please input the value for the node (max length 64): ");
                scanf(" %[^\n]%*c", input_data);

                while(position < 0 || position > list_length){
                    printf("Please input the position to add this node: ");
                    scanf(" %d", &position);
                    if(position < 0 || position > list_length){
                        printf("Skillissue. Give a value again\n");
                    }
                }

                add_node(input_data, position);
                position = -1;
                printf("Node with value \"%s\" has been added\n", input_data);
                break;

            case REMOVE_NODE:
            if(list_length == 0){
                printf("No item in list!\n");
                break;
            }
                while(position < 0 || position >= list_length){
                    printf("Please input the position to be removed: ");
                    scanf(" %d", &position);
                    if(position < 0 || position > list_length - 1){
                        printf("Skillissue. Give a value again\n");
                    }
                }

                remove_node(position);
                position = -1;
                break;
            case PRINT_LIST:
                print_list();
                break;
            case QUIT_PROGRAM:
                break;
        }
    }
    printf("Closing the program\n");
    free(pHead);
    return 0;
}