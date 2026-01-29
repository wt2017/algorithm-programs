#include <stdint.h>
#include <string.h>
#include <stdio.h>


typedef int (*compare_func)(char* left, char* right);

void bubble(char* array, int item_size, int item_num, compare_func compare) {
    for (int i=0; i<item_num; i++) {
        for (int j=0; j<item_num-1; j++) {
            char* a = array + j*item_size;
            char* b = array + (j+1)*item_size;
            if (compare(a, b) > 0) {
                char t[item_size];
                memcpy(t, a, item_size);
                memcpy(a, b, item_size);
                memcpy(b, t, item_size);
            }
        }
    }
}

int compare1(char* left, char* right) {
    if (*left < *right) {
        return 1;
    }
    return 0;
}

int main() {
    #define ITEM_NUM 6
    char test_arr[ITEM_NUM + 1] = {'a','b','c','d','e','f', '\0'};
    printf("ori array: %s\n", test_arr);
    bubble(test_arr, 1, ITEM_NUM, compare1);
    printf("sorted array: %s\n", test_arr);
    return 0;
}
