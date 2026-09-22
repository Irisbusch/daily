#include <stdio.h>

int main() {
    int index = 0;
    int number = 0;
    char buffer[100];

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    while (buffer[index] != '\0') {
        if (buffer[index] == '.') {
            buffer[index] = '!';
            number++;
        }
        index++;
    }

    printf("Number of '.' characters replaced: %d\n", number);
    printf("Modified string: %s", buffer);

    return 0;
}