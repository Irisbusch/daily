#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    printf("Enter a sentence: ");
    char buf[100];
    fgets(buf, sizeof(buf), stdin);

    char *str = strdup(buf);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    size_t len = strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';    // 把 \n 换成 \0
    }

    printf("Original: %s\n", str);
    printf("Length: %lu\n", strlen(str));

    
    char *left = str;
    char *right = str + strlen(str) - 1;
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    
    printf("Reversed: %s\n", str);
    free(str);
    return 0;
}