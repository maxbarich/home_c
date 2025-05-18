#include <stdio.h>

// Функция перевода числа в P-ичную систему
int convert_to_base(int n, int p) {
    int result = 0;
    int multiplier = 1;
    
    while (n > 0) {
        int digit = n % p;       // Получаем очередную цифру
        result += digit * multiplier; // Добавляем к результату
        n /= p;                  // Убираем обработанную цифру
        multiplier *= 10;        // Увеличиваем разряд
    }
    
    return result;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p); // Вводим число и основание
    
    // Проверяем корректность входных данных
    if (n < 0 || p < 2 || p > 9) {
        printf("Некорректные входные данные\n");
        return 1;
    }
    
    // Особый случай для нуля
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    
    // Переводим и выводим результат
    int result = convert_to_base(n, p);
    printf("%d\n", result);
    
    return 0;
}
