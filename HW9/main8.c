
void swap_negmax_last(int size, int a[]) {
    int max_neg = -2147483648; // минимальное значение для int
    int index_neg_max = -1;

    // ищем максимальный отрицательный элемент
    for (int i = 0; i < size; i++) {
        if (a[i] < 0 && a[i] > max_neg) {
            max_neg = a[i];
            index_neg_max = i;
        }
    }

    // если отрицательных элементов нет, ничего не делаем
    if (index_neg_max == -1) {
        return;
    }

    // меняем местами найденный отрицательный элемент с последним элементом массива
    int temp = a[index_neg_max];
    a[index_neg_max] = a[size - 1];
    a[size - 1] = temp;
}
