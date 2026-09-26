#include <stdio.h>

int swap_count(void); // 函数声明

int sort_desc(double *x, double *y)
{
    if (*x < *y) {
        double temp = *x;
        *x = *y;
        *y = temp;
        swap_count(); // 交换成功，调用统计函数
    }
    return 0;
}

int main()
{
    double a, b, c;
    printf("请输入三个浮点数：");
    scanf("%lf %lf %lf", &a, &b, &c);

    sort_desc(&a, &b);
    sort_desc(&a, &c);
    sort_desc(&b, &c);

    printf("从大到小排序结果：%.2f, %.2f, %.2f\n", a, b, c);
    printf("交换次数：%d\n", swap_count()); // 最终输出
    return 0;
}

int swap_count(void) {
    static int count = 0; // 静态变量，只初始化一次，函数结束依然保留值
    count++;
    return count;
}