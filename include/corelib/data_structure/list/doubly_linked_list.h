#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DoublyLinkedListNode {
    char* data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
} DoublyLinkedList;


DoublyLinkedListNode* doubly_linked_list_node_initialize(char* c);
DoublyLinkedList* doubly_linked_list_initialize(DoublyLinkedListNode* node);
void doubly_linked_list_insert_to_tail(DoublyLinkedList* list, DoublyLinkedListNode* node);
void doubly_linked_list_delete_tail_node(DoublyLinkedList* list);

#endif // DOUBLY_LINKED_LIST_H
