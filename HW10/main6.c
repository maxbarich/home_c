#include <stdio.h>
#include <string.h>

int is_palindrom(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // не палиндром
        }
    }
    return 1; // палиндром
}

int main() {
    char str[1001];
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    if (fgets(str, sizeof(str), fin) != NULL) {
        // удаляем перенос строки, если есть
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

        if (is_palindrom(str)) {
            fprintf(fout, "YES");
        } else {
            fprintf(fout, "NO");
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
