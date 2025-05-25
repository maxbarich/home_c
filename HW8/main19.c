#include <stdio.h>

int main() {
    char N[20];
    scanf("%s", N); // читаем число как строку

    // выводим каждую цифру через пробел
    for (int i = 0; N[i] != '\0'; i++) {
        printf("%c ", N[i]);
    }
    printf("\n");

    return 0;
}
