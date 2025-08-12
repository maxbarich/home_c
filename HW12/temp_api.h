#ifndef TEMP_API_H
#define TEMP_API_H

#define MAX_RECORDS 50000

typedef struct 
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TempRecord;


void print_monthly_stats(TempRecord records[], int size, int month);
void print_yearly_stats(TempRecord records[], int size);

void add_record(TempRecord records[], int *size, TempRecord new_record);
void delete_record(TempRecord records[], int *size, int index);
void sort_records(TempRecord records[], int size);
void print_records(TempRecord records[], int size);
void print_records_by_month(TempRecord records[], int size, int month);


int load_from_csv(const char *filename, TempRecord records[], int *size);

#endif