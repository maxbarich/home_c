#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

typedef struct 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} 
TempRecord;

void init_records(TempRecord **records, int *capacity);
void add_record_dynamic(TempRecord **records, int *size, int *capacity, TempRecord new_record);
void print_monthly_stats(TempRecord records[], int size, int month);
void print_yearly_stats(TempRecord records[], int size);
void delete_record(TempRecord records[], int *size, int index);
void sort_records(TempRecord records[], int size);
void print_records(TempRecord records[], int size);
void print_records_by_month(TempRecord records[], int size, int month);
int load_from_csv(const char *filename, TempRecord **records, int *size, int *capacity);

#endif