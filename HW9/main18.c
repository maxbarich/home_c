#include <stdio.h>

// Функция вычисляет среднее арифметическое элементов главной диагонали
double average_main_diagonal(int size, int matrix[size][size]) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return (double)sum / size;
}

int main() {
    int size = 5;
    int matrix[size][size];
    // Ввод матрицы
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    double avg = average_main_diagonal(size, matrix);
    int count = 0;

    // Подсчет количества элементов, превышающих среднее
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] > avg && matrix[i][j] > 0) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
