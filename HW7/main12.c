#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);
    int current_number = 1;

    while (count < n) {
        for (int i = 0; i < current_number && count < n; i++) {
            printf("%d ", current_number);
            count++;
        }
        current_number++;
    }
    printf("\n");
    return 0;
}
