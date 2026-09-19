#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

int main() {
    setlocale(LC_ALL, "");

    wchar_t *Word = malloc(100 * sizeof(wchar_t));

    wprintf(L"Enter a word: ");
    wscanf(L"%99ls", Word);
    
    wchar_t *str = wcsdup(Word);
    if (str == NULL) {
        wprintf(L"Memory allocation failed\n");
        free(Word);
        return 1;
    }

    wchar_t *left = str;
    wchar_t *right = str + wcslen(str) - 1;

    while (left < right) {
        wchar_t temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }

    wprintf(L"Reversed word: %ls\n", str);

    free(Word);
    free(str);
    return 0;
}