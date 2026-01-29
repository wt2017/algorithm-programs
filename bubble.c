#include <stdint.h>
#include <string.h>
#include <stdio.h>


typedef int (*compare_func)(void* left, void* right);

void bubble(void* array, int item_size, int item_num, compare_func compare) {
    for (int i=0; i<item_num; i++) {
        for (int j=0; j<item_num-1; j++) {
            void* a = (char*)array + j*item_size;
            void* b = (char*)array + (j+1)*item_size;
            if (compare(a, b) > 0) {
                char t[item_size];
                memcpy(t, a, item_size);
                memcpy(a, b, item_size);
                memcpy(b, t, item_size);
            }
        }
    }
}

int compare1(void* left, void* right) {
    if (*(char*)left < *(char*)right) {
        return 1;
    }
    return 0;
}

int compare2(void* left, void* right) {
    if (*(int*)left < *(int*)right) {
        return 1;
    }
    return 0;
}

int main() {
    #define ITEM_NUM 6
    char char_arr[ITEM_NUM + 1] = {'a','b','c','d','e','f', '\0'};
    printf("ori array: %s\n", char_arr);
    bubble(char_arr, 1, ITEM_NUM, compare1);
    printf("sorted array: %s\n", char_arr);

    int int_arr[ITEM_NUM] = {1,2,6,4,9,3};
    printf("\nori array: ");
    for (int i=0; i<ITEM_NUM; i++) {
        printf("%d ", int_arr[i]);
    }
    bubble(int_arr, sizeof(int), ITEM_NUM, compare2);
    printf("\nsorted array: ");
    for (int i=0; i<ITEM_NUM; i++) {
        printf("%d ", int_arr[i]);
    }

    return 0;
}
