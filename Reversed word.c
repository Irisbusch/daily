#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *Word = malloc(100);
    if (Word == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter a word: ");
    if (scanf("%99s", Word) != 1) {
        printf("Input error\n");
        free(Word);
        return 1;
    }

    size_t len = strlen(Word);
    if (len > 1) {
        char *left = Word;
        char *right = Word + len - 1;

        while (left < right) {
            char temp = *left;
            *left = *right;
            *right = temp;
            left++;
            right--;
        }
    }

    printf("Reversed word: %s\n", Word);
    free(Word);
    return 0;
}