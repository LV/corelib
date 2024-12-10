#include "unity.h"
#include <stdlib.h>
#include <string.h>
#include <corelib/data_structure/list/doubly_linked_list.h>


DoublyLinkedListNode* a = NULL;
DoublyLinkedListNode* b = NULL;
DoublyLinkedListNode* c = NULL;
DoublyLinkedList* list = NULL;

void setUp(void) {
    char* a_str = "Alberto";
    char* b_str = "Bob";
    char* c_str = "Carmelo";

    a = doubly_linked_list_node_initialize(a_str);
    b = doubly_linked_list_node_initialize(b_str);
    c = doubly_linked_list_node_initialize(c_str);

    list = doubly_linked_list_initialize(a);
}

void tearDown(void) {
    if (list) {
        doubly_linked_list_free(list);
        list = NULL;
    }

    a = b = c = NULL;
}

void test_doubly_linked_list_insertions_and_deletions(void) {
    // list = ["Alberto"]
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_NOT_NULL(list->tail);
    TEST_ASSERT_TRUE(strcmp(list->head->data, "Alberto") == 0);
    TEST_ASSERT_TRUE(strcmp(list->tail->data, "Alberto") == 0);

    doubly_linked_list_delete_tail_node(list); // list = []
    TEST_ASSERT_NULL(list->head);
    TEST_ASSERT_NULL(list->tail);

    doubly_linked_list_delete_tail_node(list); // list = []
    TEST_ASSERT_NULL(list->head);
    TEST_ASSERT_NULL(list->tail);

    doubly_linked_list_insert_to_tail(list, b); // list = [ "Bob" ]
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_NOT_NULL(list->tail);
    TEST_ASSERT_TRUE(strcmp(list->head->data, "Bob") == 0);
    TEST_ASSERT_TRUE(strcmp(list->tail->data, "Bob") == 0);

    doubly_linked_list_insert_to_tail(list, b); // list = [ "Bob", "Bob" ]
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_NOT_NULL(list->tail);
    TEST_ASSERT_TRUE(strcmp(list->head->data, "Bob") == 0);
    TEST_ASSERT_TRUE(strcmp(list->tail->data, "Bob") == 0);

    doubly_linked_list_insert_to_tail(list, c); // list = [ "Bob", "Bob", "Carmelo" ]
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_NOT_NULL(list->tail);
    TEST_ASSERT_TRUE(strcmp(list->head->data, "Bob") == 0);
    TEST_ASSERT_TRUE(strcmp(list->tail->data, "Carmelo") == 0);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_doubly_linked_list_insertions_and_deletions);
    return UNITY_END();
}
