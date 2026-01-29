#include <stdio.h>
#include <stdbool.h>

typedef struct list_node {
    int value;
    struct list_node* next;
} list_node_t;

bool have_cycle(list_node_t* head) {
    list_node_t* slow = head;
    list_node_t* fast = head->next;

    while (NULL != fast && NULL != fast->next) {
        if (slow == fast) {
            return true;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main() {
    list_node_t n1 = {1, NULL};
    list_node_t n2 = {2, &n1};
    list_node_t n3 = {3, &n2};
    list_node_t n4 = {4, &n3};
    list_node_t n5 = {5, &n4};
    list_node_t n6 = {6, &n5};
    list_node_t n7 = {7, &n6};

    bool b = have_cycle(&n7);
    printf("have %s cycle", b?"a":"not");

    printf("\n");

    n1.next = &n7; // make a cycle here
    b = have_cycle(&n7);
    printf("have %s cycle", b?"a":"not");
}