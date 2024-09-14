#include "linked_list.h"

Node *create_node(int_vector pos) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->pos = pos;
  new_node->next = NULL;
  return new_node;
}

Node *insert(Node *head, int_vector pos) {
  if (head == NULL)
    return create_node(pos);
  Node *new_node = create_node(pos);
  Node *temp = head;

  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  return head;
}

Node *insert_at_first(Node *head, int_vector pos) {
  Node *new_node = create_node(pos);
  new_node->next = head;
  return new_node;
}

void list_print(Node *head) {
  if (head == NULL) {
    return;
  }
  Node *temp = head;
  while (temp != NULL) {
    printf("(%d,%d) ", temp->pos.x, temp->pos.y);
    temp = temp->next;
  }
  printf("\n");
}
Node *removeLastNode(struct Node *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  Node *second_last = head;
  while (second_last->next->next != NULL) {
    second_last = second_last->next;
  }
  free(second_last->next);
  second_last->next = NULL;

  return head;
}

Node *removeAllNode(struct Node *head){
  if(head == NULL){
    return NULL;
  }
    Node *temp = head ,*next;
    while (temp != NULL)
    {
     next = temp->next;
     free(temp);
     temp = next;
    }
    head = NULL;
    return head;
}
