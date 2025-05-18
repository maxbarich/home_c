#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    int balance = 0;
    int i = 0;
    
    // Чтение строки до точки
    while (1) {
        scanf("%c", &str[i]);
        if (str[i] == '.') break;
        i++;
    }
    
    // Проверка баланса скобок
    for (int j = 0; j < i; j++) {
        if (str[j] == '(') {
            balance++;
        } else if (str[j] == ')') {
            balance--;
        }
        
        // Если баланс стал отрицательным - скобки неверные
        if (balance < 0) {
            printf("NO\n");
            return 0;
        }
    }
    
    // Если баланс нулевой - скобки верные
    printf(balance == 0 ? "YES\n" : "NO\n");
    
    return 0;
}
