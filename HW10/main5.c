#include <stdio.h>

int main() {
    char str[1001]; // строка не более 1000 символов
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) {
        return 1;
    }

    // читаем строку
    if (fgets(str, sizeof(str), fin) != NULL) {
        for (int i = 0; str[i]; i++) {
            if (str[i] == 'a') {
                str[i] = 'b';
            } else if (str[i] == 'b') {
                str[i] = 'a';
            } else if (str[i] == 'A') {
                str[i] = 'B';
            } else if (str[i] == 'B') {
                str[i] = 'A';
            }
            // оставляем остальные символы без изменений
        }
        fputs(str, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
