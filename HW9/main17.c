#include <stdio.h>

// Функция поиска максимума в строке из 10 элементов
int max_in_row(int row[10]) {
    int max_value = row[0];
    for (int i = 1; i < 10; i++) {
        if (row[i] > max_value) {
            max_value = row[i];
        }
    }
    return max_value;
}

int main() {
    int matrix[10][10];
    int sum_max = 0;

    // Ввод матрицы
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Для каждой строки ищем максимум и суммируем
    for (int i = 0; i < 10; i++) {
        sum_max += max_in_row(matrix[i]);
    }

    printf("%d\n", sum_max);
    return 0;
}
