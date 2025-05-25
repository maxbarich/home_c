#include <stdio.h>

int max_find(int current_max) {
    int num;
    scanf("%d", &num);
    if (num == 0) {
        return current_max;
    }
    if (num > current_max) {
        current_max = num;
    }
    return max_find(current_max);
}

int main() {
    int max_value;
    scanf("%d", &max_value);
    int result = max_find(max_value);
    printf("%d\n", result);
    return 0;
}
