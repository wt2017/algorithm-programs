#include <stdio.h>

typedef struct list_node {
    int value;
    struct list_node* next;
} list_node_t;

void reverse_list(list_node_t* head) {
    if (NULL == head) {
        return;
    }

    list_node_t* prev = NULL;
    list_node_t* curr = head;
    list_node_t* next = head->next;

    while (NULL != curr) {
        list_node_t* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

int main() {
    list_node_t n1 = {1, NULL};
    list_node_t n2 = {2, &n1};
    list_node_t n3 = {3, &n2};
    list_node_t n4 = {4, &n3};
    list_node_t n5 = {5, &n4};
    list_node_t n6 = {6, &n5};
    list_node_t n7 = {7, &n6};

    list_node_t* n = &n7;
    while (NULL != n) {
        printf("%d ", n->value);
        n = n->next;
    }

    printf("\n");
    reverse_list(&n7);
    n = &n1;

    while (NULL != n) {
        printf("%d ", n->value);
        n = n->next;
    }

    return 0;
}