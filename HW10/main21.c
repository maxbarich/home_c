#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    if (!fin || !fout) return 1;

    int star_count = 0;
    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch == '*') star_count++;
    }
    fclose(fin);

    // Ищем n, такое что n*(n+1)/2 == star_count
    int n = 1;
    int total = 0;
    int found = 0;
    while (total <= star_count) {
        total = n * (n + 1) / 2;
        if (total == star_count) {
            found = 1;
            break;
        }
        n++;
    }

    if (!found) {
        fprintf(fout, "NO\n");
        fclose(fout);
        return 0;
    }

    // Строим треугольник
    for (int i = 1; i <= n; i++) {
        int spaces = n - i;
        // выводим пробелы
        for (int s = 0; s < spaces; s++) {
            fprintf(fout, " ");
        }
        // выводим символы "*", разделённые пробелом
        for (int j = 0; j < i; j++) {
            fprintf(fout, "*");
            if (j != i - 1) fprintf(fout, " ");
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
    return 0;
}
