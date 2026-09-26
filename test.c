#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int main(void) {
    char buf[128];

    while (1) {
        printf("请输入一个整数: ");
        fflush(stdout);

        if (fgets(buf, sizeof buf, stdin) == NULL) {
            
            printf("\n输入结束。\n");
            return 0;
        }

        // 如果这一行太长，缓冲区没读到 '\n'，把剩余字符吃掉
        if (strchr(buf, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
                // 丢弃
            }
        }

        // 去掉末尾换行，方便后续判断
        buf[strcspn(buf, "\n")] = '\0';

        // 空行检查
        if (buf[0] == '\0') {
            printf("输入无效：不能为空，请重新输入。\n");
            continue;
        }

        // 用 strtol 解析
        errno = 0;
        char *endptr;
        long val = strtol(buf, &endptr, 10);

        // 没有解析到任何数字
        if (endptr == buf) {
            printf("输入无效：这不是一个整数，请重新输入。\n");
            continue;
        }

        // 解析后还有非空白字符
        while (*endptr == ' ' || *endptr == '\t') {
            endptr++;
        }
        if (*endptr != '\0') {
            printf("输入无效：整数后面有多余字符，请重新输入。\n");
            continue;
        }

        // 溢出检查
        if (errno == ERANGE || val < INT_MIN || val > INT_MAX) {
            printf("输入无效：整数超出 int 范围，请重新输入。\n");
            continue;
        }

        int num = (int)val;

        // 范围检查（按题目要求）
        if (num < 1 || num > 100) {
            printf("输入无效：整数必须在 1 到 100 之间，请重新输入。\n");
            continue;
        }

        printf("你输入的整数是: %d\n", num);
        printf("它的平方是: %d\n", num * num);
        break;
    }

    return 0;
}
