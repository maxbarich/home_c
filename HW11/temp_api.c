#include "temp_api.h"
#include <stdio.h>

void print_monthly_stats(const TemperatureRecord *data, int count, int month) {
    int min = 99, max = -99, sum = 0, records = 0;

    for (int i = 0; i < count; i++) {
        if (data[i].month == month) {
            if (data[i].temperature < min) min = data[i].temperature;
            if (data[i].temperature > max) max = data[i].temperature;
            sum += data[i].temperature;
            records++;
        }
    }

    if (records == 0) return;  // Пропускаем пустые месяцы

    printf("Month %02d: Avg=%.1fC, Min=%dC, Max=%dC\n", 
           month, (float)sum / records, min, max);
}

void print_yearly_stats(const TemperatureRecord *data, int count) {
    int min = 99, max = -99, sum = 0;

    for (int i = 0; i < count; i++) {
        if (data[i].temperature < min) min = data[i].temperature;
        if (data[i].temperature > max) max = data[i].temperature;
        sum += data[i].temperature;
    }

    printf("=== Yearly Stats ===\n");
    printf("Avg=%.1fC, Min=%dC, Max=%dC\n", (float)sum / count, min, max);
}