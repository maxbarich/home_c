#include <stdio.h>
#include <string.h>

int main() {
    char line[101];
    char surname[50], name[50], otchestvo[50];

    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    // читаем строку с фамилией, именем и отчеством
    if (fgets(line, sizeof(line), fin) != NULL) {
        // разбиваем строку по пробелам
        sscanf(line, "%s %s %s", surname, name, otchestvo);
        // формируем приветствие
        fprintf(fout, "Hello, %s %s!", name, surname);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
