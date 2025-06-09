#include <stdio.h>

void check_cell_color(const char coord[]) {
    char letter = coord[0];
    char digit_char = coord[1];

    int column = letter - 'A' + 1; // преобразуем букву в число от 1 до 8
    int row = digit_char - '0';    // преобразуем цифру в число

    int sum = column + row;
    if (sum % 2 == 0) {
        printf("BLACK\n");
    } else {
        printf("WHITE\n");
    }
}

int main() {
    char coord[3];
    scanf("%2s", coord); // читаем строку из двух символов
    check_cell_color(coord);
    return 0;
}
