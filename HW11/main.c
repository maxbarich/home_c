#include "temp_api.h"
#include <stdio.h>
int main() 
{
    // Тестовые данные
    TemperatureRecord data[] = 
    {
        {2023, 1, 15, 12, 0, -5},
        {2023, 1, 16, 13, 0, -8},
        {2023, 2, 20, 9, 0, 2},
        {2023, 2, 21, 15, 0, 5},
        {2023, 12, 31, 23, 59, -10}
    };
    int count = sizeof(data) / sizeof(data[0]);

    // Вывод статистики
    printf("=== Monthly Stats ===\n");
    for (int month = 1; month <= 12; month++) 
    {
        print_monthly_stats(data, count, month);
    }
    print_yearly_stats(data, count);

    return 0;
}