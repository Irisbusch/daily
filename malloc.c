#include <stdlib.h>
#include <stdio.h>

int main() {
    // 1. 申请内存：分配 10 个 int 的空间
    int *arr = malloc(sizeof(int) * 10);

    // 2. 检查是否分配成功
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    // 3. 使用内存
    for (int i = 0; i < 10; i++) {
        arr[i] = i * i;
    }

    for (int i = 0; i < 10; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
    }

    // 4. 释放内存
    free(arr);
    arr = NULL;  // 避免悬空指针

    return 0;
}