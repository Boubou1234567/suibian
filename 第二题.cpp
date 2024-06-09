#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** num; // 修改为指针，用于指向动态分配的数组

int Difference(int n, int m, int a, int b) {
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = n; i < n + a; i++) {
        for (int j = m; j < m + b; j++) {
            if (num[i][j] > max) {
                max = num[i][j];
            }
            if (num[i][j] < min) {
                min = num[i][j];
            }
        }
    }
    return max - min; // 返回极差
}

void FreeMemory(int** arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int n, m, nn, mm;
    scanf("%d %d %d %d", &n, &m, &nn, &mm);

    // 动态分配二维数组的内存
    num = (int**)malloc(n * sizeof(int*));
    if (!num) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        num[i] = (int*)malloc(m * sizeof(int));
        if (!num[i]) {
            FreeMemory(num, i); // 释放之前分配的内存
            return 1;
        }
    }

    // 输入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    long long max = 0; // 保证足够大以存储结果
    for (int i = 0; i <= n - nn; i++) {
        for (int j = 0; j <= m - mm; j++) {
            long long sum = 0;
            // 计算子矩阵的元素和
            for (int ii = i; ii < i + nn; ii++) {
                for (int jj = j; jj < j + mm; jj++) {
                    sum += num[ii][jj];
                }
            }
            // 计算极差
            long long temp = Difference(i, j, nn, mm);
            long long product = temp * sum;
            if (product > max) {
                max = product;
            }
        }
    }
    
    printf("%lld\n", max);

    // 释放二维数组的内存
    FreeMemory(num, n);

    return 0;
}
