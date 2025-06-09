void print_digit(char s[]) {
    int counts[10] = {0};

    // Подсчет количества каждой цифры в строке
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            counts[s[i] - '0']++;
        }
    }

    // Вывод цифр и их количества по возрастанию
    for (int digit = 0; digit <= 9; digit++) {
        if (counts[digit] > 0) {
            printf("%d %d\n", digit, counts[digit]);
        }
    }
}
