#include <stdio.h>
#include <string.h>

void pack_string(char s[]) {
    int len = strlen(s);
    int count = 1;
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            count++;
        } else {
            if (s[i] != '.') {
                printf("%c%d", s[i], count);
            }
            count = 1;
        }
    }
    // Обработка последнего символа
    if (len > 0 && s[len - 1] != '.') {
        printf("%c%d", s[len - 1], count);
    }
}

int main() {
    char s[1001];
    scanf("%1000s", s);
    pack_string(s);
    return 0;
}
