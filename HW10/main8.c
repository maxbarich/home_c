#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

int main() {
    char str[1001]; // строка не более 1000 символов
    int numbers[1000]; // максимально возможное количество чисел
    int count = 0;

    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    if (fgets(str, sizeof(str), fin) != NULL) {
        int i = 0;
        while (str[i]) {
            // пропускаем нецифровые символы
            while (str[i] && !isdigit((unsigned char)str[i])) {
                i++;
            }
            if (str[i]) {
                // нашли число, считываем его
                int num = 0;
                while (str[i] && isdigit((unsigned char)str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                numbers[count++] = num;
            }
        }
        // сортируем массив чисел
        qsort(numbers, count, sizeof(int), compare);
        // выводим отсортированные числа
        for (int j = 0; j < count; j++) {
            if (j > 0) {
                fprintf(fout, " ");
            }
            fprintf(fout, "%d", numbers[j]);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
