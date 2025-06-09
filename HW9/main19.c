#include <stdio.h>

// Функция для вычисления произведения цифр числа, учитывая только цифры с нужным паритетом
int product_of_digits(int number, int even_required) {
    int product = 1;
    int has_digit = 0; // чтобы учесть случай, когда цифр нет (например, число 0)
    if (number == 0) {
        if (even_required) {
            return 0; // цифра 0, и она четная, возвращаем 0
        } else {
            return 0; // цифра 0, нечетная, возвращаем 0
        }
    }
    while (number > 0) {
        int digit = number % 10;
        if (even_required && digit % 2 == 0) {
            product *= digit;
            has_digit = 1;
        } else if (!even_required && digit % 2 != 0) {
            product *= digit;
            has_digit = 1;
        }
        number /= 10;
    }
    // Если не нашли цифр нужного паритета, возвращаем 0
    if (!has_digit) return 0;
    return product;
}

int main() {
    int arr[10], count_even = 0, count_odd = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) count_even++;
        else count_odd++;
    }

    int replace_with_even = (count_even > count_odd) ? 1 : 0;

    for (int i = 0; i < 10; i++) {
        if (replace_with_even && arr[i] % 2 != 0) {
            arr[i] = product_of_digits(arr[i], 0); // заменяем нечетные числа
        } else if (!replace_with_even && arr[i] % 2 == 0) {
            arr[i] = product_of_digits(arr[i], 1); // заменяем четные числа
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d", arr[i]);
        if (i < 9) printf(" ");
    }
    printf("\n");
    return 0;
}

