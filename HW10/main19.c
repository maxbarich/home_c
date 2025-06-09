#include <stdio.h>
#include <string.h>

// Функция для построения максимального палиндрома
void compose_palindrome(const char *input, char *output) {
    int freq[26] = {0};
    int len = strlen(input);

    // Подсчет частот букв
    for (int i = 0; i < len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            freq[input[i] - 'a']++;
        }
    }

    // Построение половины палиндрома
    char first_half[1001] = "";
    int idx = 0;
    int odd_char_index = -1; // индекс буквы с нечётной частотой
    for (int i = 0; i < 26; i++) {
        int count = freq[i];
        // добавляем половину
        for (int j = 0; j < count / 2; j++) {
            first_half[idx++] = 'a' + i;
        }
        // ищем букву с нечётной частотой
        if (count % 2 != 0) {
            if (odd_char_index == -1 || i < odd_char_index) {
                odd_char_index = i;
            }
        }
    }
    first_half[idx] = '\0';

    // сортируем половину
    for (int i = 0; i < idx - 1; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (first_half[i] > first_half[j]) {
                char temp = first_half[i];
                first_half[i] = first_half[j];
                first_half[j] = temp;
            }
        }
    }

    // формируем полный палиндром
    char second_half[1001] = "";
    int len_half = strlen(first_half);
    for (int i = len_half - 1; i >= 0; i--) {
        int pos = len_half - 1 - i;
        second_half[pos] = first_half[i];
    }
    second_half[len_half] = '\0';

    // собираем итог
    if (odd_char_index != -1) {
        // есть центральная буква с нечётной частотой
        char middle_char = 'a' + odd_char_index;
        sprintf(output, "%s%c%s", first_half, middle_char, second_half);
    } else {
        // без центральной буквы
        sprintf(output, "%s%s", first_half, second_half);
    }
}

int main() {
    char input[1001], output[1001];

    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) return 1;

    if (fgets(input, sizeof(input), fin)) {
        // удаляем перенос строки, если есть
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';

        compose_palindrome(input, output);
        fprintf(fout, "%s", output);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
