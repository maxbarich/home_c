int sum_between_ab(int from, int to, int size, int a[]) {
    int sum = 0;
    int lower = from < to ? from : to;
    int upper = from > to ? from : to;
    for (int i = 0; i < size; i++) {
        if (a[i] >= lower && a[i] <= upper) {
            sum += a[i];
        }
    }
    return sum;
}

