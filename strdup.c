#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char word[100];
    int num;
    printf("Enter a word: ");
    scanf("%s", word);
    printf("Enter a number: ");
    scanf("%d", &num);
    
    char *str = strdup(word);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < num; i++) {
        char *temp = str;
        while (*temp) {
            putchar(*temp);
            temp++;
        }
        putchar('\n');
    }
    free(str);
    return 0;
}