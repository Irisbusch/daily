#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    buffer[strcspn(buffer, "\n")] = '\0';

    char *p = malloc(strlen(buffer) + 1);
    if (p == NULL) {          
        printf("内存分配失败\n");
        return 1;
    }
    strcpy(p, buffer);

    for (int i = (int)strlen(p) - 1; i >= 0; i--) {
        printf("%c", p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}