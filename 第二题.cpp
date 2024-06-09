#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int** num; // �޸�Ϊָ�룬����ָ��̬���������

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
    return max - min; // ���ؼ���
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

    // ��̬�����ά������ڴ�
    num = (int**)malloc(n * sizeof(int*));
    if (!num) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        num[i] = (int*)malloc(m * sizeof(int));
        if (!num[i]) {
            FreeMemory(num, i); // �ͷ�֮ǰ������ڴ�
            return 1;
        }
    }

    // �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    long long max = 0; // ��֤�㹻���Դ洢���
    for (int i = 0; i <= n - nn; i++) {
        for (int j = 0; j <= m - mm; j++) {
            long long sum = 0;
            // �����Ӿ����Ԫ�غ�
            for (int ii = i; ii < i + nn; ii++) {
                for (int jj = j; jj < j + mm; jj++) {
                    sum += num[ii][jj];
                }
            }
            // ���㼫��
            long long temp = Difference(i, j, nn, mm);
            long long product = temp * sum;
            if (product > max) {
                max = product;
            }
        }
    }
    
    printf("%lld\n", max);

    // �ͷŶ�ά������ڴ�
    FreeMemory(num, n);

    return 0;
}
