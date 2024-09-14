#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct int_vector {
  int x;
  int y;
} int_vector;
typedef struct Node {
  int_vector pos;
  struct Node *next;
} Node;

Node *create_node(int_vector);
Node *insert(Node *, int_vector);
Node *insert_at_first(Node *, int_vector);
void list_print(Node *);
Node *removeLastNode(struct Node *head);
Node *removeAllNode(struct Node *head);
#endif
