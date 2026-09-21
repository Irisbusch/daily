#include <stdio.h>

int main(void) {
    const int rows = 6;

    for (int i = 1; i <= rows; i++) {

        for (int s = 1; s <= rows - i; s++) {
            printf(" ");
        }

        for (int j = 0; j < i; j++) {
            printf("%c", 'A' + j);
        }

        for (int j = i - 2; j >= 0; j--) {
            printf("%c", 'A' + j);
        }

        printf("\n");
    }
    return 0;
}