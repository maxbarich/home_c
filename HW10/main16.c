#include <stdio.h>
#include <string.h>

int main() {
    char line[1001];
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    if (fgets(line, sizeof(line), fin) != NULL) {
        // Обработка строки
        char result[1001] = "";
        int i = 0;
        int len = strlen(line);
        while (i < len) {
            // Проверяем, есть ли слово "Ling" начиная с текущей позиции
            if (strncmp(&line[i], "Ling", 4) == 0) {
                // Добавляем "Cao" в результат
                strcat(result, "Cao");
                i += 4;
            } else {
                // Добавляем текущий символ
                int result_len = strlen(result);
                result[result_len] = line[i];
                result[result_len + 1] = '\0';
                i++;
            }
        }
        // Записываем результат
        fprintf(fout, "%s", result);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
