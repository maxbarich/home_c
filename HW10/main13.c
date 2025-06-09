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
        // Удаляем перенос строки, если есть
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        // Находим последний слеш '/', чтобы отделить имя файла
        char *last_slash = strrchr(line, '/');
        // Если слеша нет, рассматриваем всю строку как имя файла
        char *filename = last_slash ? last_slash + 1 : line;

        // Ищем точку в имени файла для расширения
        char *dot = strrchr(filename, '.');

        if (dot != NULL) {
            // Есть расширение, заменяем его на ".html"
            strcpy(dot, ".html");
        } else {
            // Нет расширения, добавляем ".html" в конец
            strcat(filename, ".html");
        }

        // Если есть слеш, то нужно вставить обратно в строку
        if (last_slash != NULL) {
            // копируем в исходную строку
            size_t prefix_len = last_slash - line + 1; // включительно слеш
            char new_line[1001];
            strncpy(new_line, line, prefix_len);
            new_line[prefix_len] = '\0';
            strcat(new_line, filename);
            fprintf(fout, "%s", new_line);
        } else {
            // без слеша, просто выводим изменённое имя
            fprintf(fout, "%s", filename);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
