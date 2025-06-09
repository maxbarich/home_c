#include <stdio.h>
#include <ctype.h>

int main() {
    char line[1001];
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    if (fgets(line, sizeof(line), fin) != NULL) {
        int i = 0;
        int len = 0;
        int started = 0; // флаг, что мы начали писать строку
        while (line[i] != '\0') {
            // пропускаем начальные пробелы
            while (line[i] != '\0' && isspace((unsigned char)line[i])) {
                i++;
            }
            if (line[i] == '\0') break;

            // если не первый символ, вставляем один пробел
            if (started) {
                fputc(' ', fout);
            }

            // выводим слово
            while (line[i] != '\0' && !isspace((unsigned char)line[i])) {
                fputc(line[i], fout);
                i++;
            }
            started = 1;
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
