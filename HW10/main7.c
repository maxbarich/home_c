#include <stdio.h>
#include <ctype.h>

int main() {
    char str[10001]; // строка не более 10 000 символов
    int count_lower = 0;
    int count_upper = 0;

    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout) {
        return 1;
    }

    if (fgets(str, sizeof(str), fin) != NULL) {
        // Обходим строку и считаем буквы
        for (int i = 0; str[i]; i++) {
            if (isalpha((unsigned char)str[i])) {
                if (islower((unsigned char)str[i])) {
                    count_lower++;
                } else if (isupper((unsigned char)str[i])) {
                    count_upper++;
                }
            }
        }
        fprintf(fout, "%d %d", count_lower, count_upper);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
