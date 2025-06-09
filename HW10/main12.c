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

        // Разбиваем строку на слова по пробелам
        char *word = strtok(line, " ");
        while (word != NULL) {
            fprintf(fout, "%s\n", word);
            word = strtok(NULL, " ");
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
