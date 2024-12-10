#include <stddef.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode {
    char* data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
} DoublyLinkedListNode;

DoublyLinkedListNode* doubly_linked_list_node_initialize(char* c) {
    struct DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));

    node->data = c;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


typedef struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
} DoublyLinkedList;

DoublyLinkedList* doubly_linked_list_initialize(DoublyLinkedListNode* node) {
    struct DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));

    list->head = node;
    list->tail = node;

    return list;
}

void doubly_linked_list_insert(DoublyLinkedList* list, char* c) {
    DoublyLinkedListNode* node = doubly_linked_list_node_initialize(c);

    if (list->head == NULL) {
        // list is empty
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
}

void doubly_linked_list_delete(DoublyLinkedList* list) {
    // Assumes that if head is NULL, tail must be NULL
    if (list->head == NULL) return;
    if (list->head == list->tail) {
        DoublyLinkedListNode* node = list->head;
        list->head = NULL;
        list->tail = NULL;
        free(node);
        return;
    }

    DoublyLinkedListNode* new_tail = list->tail->prev;
    list->tail->prev = NULL;
    free(new_tail->next);
    new_tail->next = NULL;
    list->tail = new_tail;
    return;
}
