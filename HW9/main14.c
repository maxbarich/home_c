int count_bigger_abs(int n, int a[]) {
    if (n == 0) return 0;

    int max_element = a[0];
    // Находим максимальный элемент
    for (int i = 1; i < n; i++) {
        if (a[i] > max_element) {
            max_element = a[i];
        }
    }

    int max_abs = (max_element >= 0) ? max_element : -max_element;
    int count = 0;

    // считаем элементы, превосходящие по модулю максимальный элемент
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (-a[i] > max_abs) {
                count++;
            }
        } else {
            if (a[i] > max_abs) {
                count++;
            }
        }
    }

    return count;
}
