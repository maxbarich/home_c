#include <stdint.h>

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;  // от -99 до 99
} TemperatureRecord;

// Статистика за год
void print_yearly_stats(const TemperatureRecord *data, int count);

// Статистика за месяц
void print_monthly_stats(const TemperatureRecord *data, int count, int month);