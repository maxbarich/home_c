#include <stdio.h>

void print_sequence(int A, int B) {
    if (A == B) {
        printf("%d ", A);
        return;
    }
    if (A < B) {
        printf("%d ", A);
        print_sequence(A + 1, B);
    } else {
        printf("%d ", A);
        print_sequence(A - 1, B);
    }
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    print_sequence(A, B);
    return 0;
}
