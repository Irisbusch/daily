#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *firstWord = malloc(100 * sizeof(char));
    char *secondWord = malloc(100 * sizeof(char));
    printf("Enter the first word: ");
    scanf("%s", firstWord);
    printf("Enter the second word: ");
    scanf("%s", secondWord);
    
    char *combined = malloc(strlen(firstWord) + strlen(secondWord) + 2); // +1 for space, +1 for null terminator
    
    if (combined == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    char *p = combined;

    while (*firstWord) {
        *p++ = *firstWord++;
    }
    
    *p = ' '; // Add space
    p++; // Move to the next position
    
    while (*secondWord) {
        *p++ = *secondWord++;
    }
    *p = '\0'; // Add null terminator

    char *temp = combined;
    while (*temp){
        putchar(*temp);
        temp++;
    }
    putchar('\n');
    free(combined);
    free(firstWord);
    free(secondWord);

}