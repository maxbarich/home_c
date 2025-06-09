#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функция для получения кодовой цифры для согласных букв
char get_code(char c) {
    // Карта соответствия букв цифрам
    if (strchr("bfpv", c)) return '1';
    if (strchr("cgjkqsxz", c)) return '2';
    if (strchr("dt", c)) return '3';
    if (c == 'l') return '4';
    if (strchr("mn", c)) return '5';
    if (c == 'r') return '6';
    return '0'; // гласные и другие буквы
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) return 1;

    char word[21];
    if (fgets(word, sizeof(word), fin)) {
        // Удаляем перенос строки, если есть
        size_t len = strlen(word);
        if (len > 0 && word[len - 1] == '\n') word[len - 1] = '\0';

        // Первая буква сохраняется в коде
        char result[5] = {0};
        result[0] = tolower(word[0]);

        char prev_code = get_code(tolower(word[0]));
        int res_idx = 1;

        for (int i = 1; word[i] != '\0' && res_idx < 4; i++) {
            char c = tolower(word[i]);
            if (strchr("aehiouwy", c)) {
                // гласные и w, y - игнорируем
                continue;
            }
            char code = get_code(c);
            if (code != '0' && code != prev_code) {
                result[res_idx++] = code;
                prev_code = code;
            } else if (code != '0') {
                // если совпадает с предыдущей, пропускаем
                continue;
            }
        }

        // если длина результата меньше 4, дополняем нулями
        while (res_idx < 4) {
            result[res_idx++] = '0';
        }

        // выводим результат
        fprintf(fout, "%s", result);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
