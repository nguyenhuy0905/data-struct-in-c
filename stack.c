#include <stdio.h>
#include <stdlib.h>
typedef struct {
    void *next;
    char *data;
} Node;

Node *head = NULL;

Node* push(char *data){
    Node *new = (Node*)malloc(sizeof(Node));
    if(new == NULL){
        printf("Error, memo allocation malfunctioned\n");
        return NULL;
    } 
    new->data = data;
    if(head == NULL){
        head = new;
        new->next = NULL;     
    }
    else{
        new->next = head;
        head = new;
    }
    return new;
}

/// remove and return the head of the stack
Node *pop(){
    if(head == NULL){
        printf("Stack is empty!\n");
        return NULL;
    }
    Node *to_pop = head;
    if(head->next == NULL) head = NULL;
    else head = head->next;
    to_pop->next = NULL;

    return to_pop;
}

void print_stack(){
    if(head == NULL){
        printf("Stack is empty!\n");
        return;
    }
    Node *curr = head;
    printf("The stack is as follow:\n");
    while(curr != NULL){
        printf("%s->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(void)
{
    push("Never gonna give you up");
    push("Never gonna let you down");
    print_stack();
    printf("%s\n",pop()->data); 
    print_stack();
    printf("%s\n",pop()->data);
    print_stack();

    push("Never gonna run around and hurt you");
    print_stack();
    return EXIT_SUCCESS;
}
