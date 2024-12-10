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

#endif // DOUBLY_LINKED_LIST_H
