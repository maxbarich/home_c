#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrom(const char *str) {
    int count[26] = {0};
    int length = 0;

    // Подсчет частот букв
    for (int i = 0; str[i]; i++) {
        if (islower((unsigned char)str[i])) {
            count[str[i] - 'a']++;
            length++;
        }
    }

    int odd_counts = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0)
            odd_counts++;
        if (odd_counts > 1)
            return 0; // нельзя составить палиндром
    }

    // Проверка по длине
    if ((length % 2 == 0 && odd_counts == 0) || (length % 2 == 1 && odd_counts == 1))
        return 1;
    return 0;
}

int main() {
    char line[1001];
    FILE *fin = fopen("input.txt", "r");
    if (!fin) {
        printf("NO\n");
        return 0;
    }

    if (fgets(line, sizeof(line), fin)) {
        // удаляем перенос строки, если есть
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        if (is_palindrom(line))
            printf("YES\n");
        else
            printf("NO\n");
    } else {
        printf("NO\n");
    }

    fclose(fin);
    return 0;
}
