#include <stdio.h>
#include <stdlib.h>

typedef struct {
  void *next;
  char *data;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *enqueue(char *data) {
  Node *new = (Node *)malloc(sizeof(Node));
  if (new == NULL) {
    printf("Error with memo allocation\n");
    return NULL;
  }
  new->data = data;
  if (head == NULL) {
    // first node in queue
    head = new;
    new->next = NULL;
    tail = new;
  } else {
    tail->next = new;
    new->next = NULL;
    tail = new;
  }
  return new;
}

Node *dequeue() {
  if (head == NULL) {
    printf("Queue is empty!\n");
    return NULL;
  }
  Node *to_dequeue = head;
  if (head->next == NULL) {
    head = NULL;
    tail = NULL;
  } else
    head = head->next;

  return to_dequeue;
}

void print_queue() {
  if (head == NULL) {
    printf("Queue is empty!\n");
    return;
  }
  printf("The values are as follow:\n");
  Node *curr = head;
  while (curr != NULL) {
    printf("%s -> ", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

int main(void) {
  // check if enqueue is doing correct
  enqueue("Never gonna give you up");
  enqueue("Never gonna let you down");
  print_queue();

  // check if dequeue is doing correct
  dequeue();
  print_queue();
  dequeue();
  print_queue();

  // check whether the special case of post-removing-everything is checked
  enqueue("Never gonna run around and desert you");
  print_queue();

  return 0;
}
