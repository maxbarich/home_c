#include <stdio.h>

int main() {
    int positives[10], negatives[10];
    int count_pos = 0, count_neg = 0;
    int num;

    // Чтение 10 чисел
    for (int i = 0; i < 10; i++) {
        scanf("%d", &num);
        if (num > 0) {
            positives[count_pos++] = num;
        } else if (num < 0) {
            negatives[count_neg++] = num;
        }
        // нули игнорируем
    }

    // Вывод положительных, затем отрицательных чисел
    for (int i = 0; i < count_pos; i++) {
        printf("%d ", positives[i]);
    }
    for (int i = 0; i < count_neg; i++) {
        printf("%d ", negatives[i]);
    }
    printf("\n");

    return 0;
}
