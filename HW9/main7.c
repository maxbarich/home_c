#include <stdio.h>

int find_missing_number() {
    int min_val = 1001;
    int max_val = 0;
    int sum = 0;
    int num;

    while (scanf("%d", &num), num != 0) {
        sum += num;
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }

    int total_sum = (max_val + min_val) * (max_val - min_val + 1) / 2;

    return total_sum - sum;
}

int main() {
    int missing_number = find_missing_number();
    printf("%d\n", missing_number);
    return 0;
}
