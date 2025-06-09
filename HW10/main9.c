#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char str[1001]; // строка не более 1000 символов
    bool seen[256] = { false }; // массив для отслеживания уже встреченных символов
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    if (fgets(str, sizeof(str), fin) != NULL) {
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            char c = str[i];
            if (c == ' ') {
                continue; // пропускаем пробелы
            }
            if (!seen[(unsigned char)c]) {
                seen[(unsigned char)c] = true;
                fputc(c, fout);
            }
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
