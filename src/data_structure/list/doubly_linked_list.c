#include <corelib/data_structure/list/doubly_linked_list.h>
#include <stddef.h>
#include <stdlib.h>

DoublyLinkedListNode* doubly_linked_list_node_initialize(char* c) {
    struct DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));
    if (node == NULL)
        return NULL; // malloc failure

    node->data = c;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

DoublyLinkedList* doubly_linked_list_initialize(DoublyLinkedListNode* node) {
    struct DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    if (list == NULL)
        return NULL; // malloc failure

    list->head = node;
    list->tail = node;

    return list;
}

void doubly_linked_list_insert_to_tail(DoublyLinkedList* list, DoublyLinkedListNode* node) {
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

void doubly_linked_list_delete_tail_node(DoublyLinkedList* list) {
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
