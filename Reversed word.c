#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char Word[100];

    printf("Enter a word: ");
    scanf("%s", Word);
    
    char *str = strdup(Word);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        free(Word);
        return 1;
    }

    char *left = str;
    char *right = str + strlen(str) - 1;

    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }

    printf("Reversed word: %s\n", str);

    free(Word);
    free(str);
    return 0;


}