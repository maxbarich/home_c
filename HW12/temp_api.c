#include <stdio.h>
#include <stdlib.h>
#include "temp_api.h"

void add_record(TempRecord records[], int *size, TempRecord new_record) 
{
    if (*size < MAX_RECORDS) 
	{
        records[(*size)++] = new_record;
    }
}

void delete_record(TempRecord records[], int *size, int index) 
{
    if (index >= 0 && index < *size) 
	{
        for (int i = index; i < *size - 1; i++) 
		{
            records[i] = records[i + 1];
        }
        (*size)--;
    }
}

int compare(const void *a, const void *b) 
{
    TempRecord *r1 = (TempRecord *)a;
    TempRecord *r2 = (TempRecord *)b;

    if (r1->year != r2->year) return r1->year - r2->year;
    if (r1->month != r2->month) return r1->month - r2->month;
    if (r1->day != r2->day) return r1->day - r2->day;
    if (r1->hour != r2->hour) return r1->hour - r2->hour;
    return r1->minute - r2->minute;
}

void sort_records(TempRecord records[], int size) 
{
    qsort(records, size, sizeof(TempRecord), compare);
}

void print_records(TempRecord records[], int size) 
{
    for (int i = 0; i < size; i++) 
	{
        printf("%04d-%02d-%02d %02d:%02d -> %d C\n",
               records[i].year, records[i].month, records[i].day,
               records[i].hour, records[i].minute, records[i].temperature);
    }
}

void print_records_by_month(TempRecord records[], int size, int month) 
{
    int found = 0;
    for (int i = 0; i < size; i++) 
	{
        if (records[i].month == month) 
		{
            printf("%04d-%02d-%02d %02d:%02d -> %d C\n",
                   records[i].year, records[i].month, records[i].day,
                   records[i].hour, records[i].minute, records[i].temperature);
            found = 1;
        }
    }
    if (!found) 
	{
        printf("No records found for month %d.\n", month);
    }
}

void print_monthly_stats(TempRecord records[], int size, int month) 
{
    int count = 0, sum = 0, min = 100, max = -100;
    for (int i = 0; i < size; i++) 
	{
        if (records[i].month == month) 
		{
            int t = records[i].temperature;
            sum += t;
            if (t < min) min = t;
            if (t > max) max = t;
            count++;
        }
    }
    if (count == 0) 
	{
        printf("No data for month %d.\n", month);
        return;
    }
    printf("Month %d Statistics:\n", month);
    printf("  Average Temperature: %d C\n", sum / count);
    printf("  Minimum Temperature: %d C\n", min);
    printf("  Maximum Temperature: %d C\n", max);
}

void print_yearly_stats(TempRecord records[], int size) 
{
    if (size == 0) 
	{
        printf("No yearly data available.\n");
        return;
    }
    int sum = 0, min = 100, max = -100;
    for (int i = 0; i < size; i++) 
	{
        int t = records[i].temperature;
        sum += t;
        if (t < min) min = t;
        if (t > max) max = t;
    }
    printf("Yearly Statistics:\n");
    printf("  Average Temperature: %d C\n", sum / size);
    printf("  Minimum Temperature: %d C\n", min);
    printf("  Maximum Temperature: %d C\n", max);
}

int load_from_csv(const char *filename, TempRecord records[], int *size) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
	{
        perror("Error opening file");
        return 0;
    }

    TempRecord temp;
    while (fscanf(file, "%d;%d;%d;%d;%d;%d",
                  &temp.year, &temp.month, &temp.day,
                  &temp.hour, &temp.minute, &temp.temperature) == 6) 				  
	{
        add_record(records, size, temp);
    }

    fclose(file);
    return 1;
}