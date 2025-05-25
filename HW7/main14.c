#include <stdio.h>

int main() {
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num % 2 != 0)
            printf("%d ", num);
    }
    printf("\n");
    return 0;
}
