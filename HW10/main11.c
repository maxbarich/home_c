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
        // Удаляем перенос строки, если есть
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        int count = 0;
        char *ptr = line;
        while (*ptr) {
            // пропускаем пробелы
            while (*ptr && isspace((unsigned char)*ptr)) {
                ptr++;
            }
            if (*ptr == '\0') break;

            // начинаем слово
            char *start = ptr;
            while (*ptr && !isspace((unsigned char)*ptr)) {
                ptr++;
            }
            int word_len = ptr - start;
            if (word_len > 0) {
                // проверяем последний символ слова
                char last_char = start[word_len - 1];
                if (last_char == 'a' || last_char == 'A') {
                    count++;
                }
            }
        }
        fprintf(fout, "%d", count);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
