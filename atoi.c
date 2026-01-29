#include <stdio.h>
#include <ctype.h>

int atoi(char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    // handle whitespace
    while (isspace(str[i])) {
        i++;
    }
    
    // handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    // convert digits to integer
    while (str[i] > '0' && str[i] < '9') {
        result = result*10 + (str[i]-'0');
        i++;
    }
    
    return sign * result;
}

int main() {
    char* test1 = "74823";
    printf("%d", atoi(test1));

    printf("\n");

    char* test2 = "74 823";
    printf("%d", atoi(test2));
    return 0;
}
