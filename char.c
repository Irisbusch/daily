#include <stdio.h>

int main(void) {
    printf("%c\n", 'X');      // X
    printf("%d\n", 'X');      // 88（ASCII 码）

    printf("%s\n", "X");      // X
    printf("%zu\n", sizeof('X'));   // 4（C）或 1（C++）
    printf("%zu\n", sizeof("X"));   // 2

    // 字符可以用 %c 打印，也可以用 %d 打印其编码
    char c = 'X';
    printf("%c %d\n", c, c);  // X 88
    return 0;
}