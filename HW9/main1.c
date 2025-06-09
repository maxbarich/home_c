void sort_even_odd(int n, int a[]) {
    int temp[n]; // временный массив для хранения результата
    int index = 0;

    // Сначала копируем все четные элементы
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[index++] = a[i];
        }
    }

    // Затем копируем все нечетные элементы
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[index++] = a[i];
        }
    }

    // Копируем обратно в исходный массив
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
