#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char line[1001];
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    if (fgets(line, sizeof(line), fin) != NULL) {
        int len = strlen(line);
        // Массив для хранения индексов символов, игнорируя пробелы
        int indices[1000];
        int count = 0;

        // Заполняем массив индексов символов без пробелов
        for (int i = 0; i < len; i++) {
            if (!isspace((unsigned char)line[i])) {
                indices[count++] = i;
            }
        }

        // Меняем местами пары соседних символов
        for (int i = 0; i + 1 < count; i += 2) {
            int idx1 = indices[i];
            int idx2 = indices[i + 1];

            // Меняем местами символы
            char temp = line[idx1];
            line[idx1] = line[idx2];
            line[idx2] = temp;
        }

        // Записываем результат
        fprintf(fout, "%s", line);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
