#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transformMatrix(int matrix[][100], int n) {
    int lowerLeftRowStart = 0;
    int lowerLeftColStart = n / 2;
    int upperRightRowStart = n / 2;
    int upperRightColStart = 0;

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            // Swap elements in lower left block with upper right block
            swap(&matrix[lowerLeftRowStart + i][lowerLeftColStart + j],
                 &matrix[upperRightRowStart + i][upperRightColStart + j]);
        }
    }
}

int main() {
    int n;
    printf("请输入矩阵维数n (n为奇数): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("矩阵维数n必须为奇数。\n");
        return 1;
    }

    int matrix[100][100];

    printf("请输入%dx%d矩阵（行内空格分隔，行间换行分隔）:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    transformMatrix(matrix, n);

    printf("变换后的矩阵:\n");
    printMatrix(matrix, n);

    return 0;
}