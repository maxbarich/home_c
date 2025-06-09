#include <stdio.h>

int main() {
    int matrix[5][5];
    int sum = 0;

    // Ввод 25 чисел
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Вычисление следа матрицы
    for (int i = 0; i < 5; i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);
    return 0;
}
