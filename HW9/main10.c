#include <stdio.h>
#include <limits.h>

void find_min_sum_pair(int a[], int size) {
    int min_sum = INT_MAX;
    int index1 = -1, index2 = -1;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int sum = a[i] + a[j];
            if (sum < min_sum) {
                min_sum = sum;
                index1 = i;
                index2 = j;
            }
        }
    }

    if (index1 < index2)
        printf("%d %d\n", index1, index2);
    else
        printf("%d %d\n", index2, index1);
}

int main() {
    int arr[30];
    for (int i = 0; i < 30; i++) {
        scanf("%d", &arr[i]);
    }
    find_min_sum_pair(arr, 30);
    return 0;
}
