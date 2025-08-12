#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "temp_functions.h"

#define MAX_LINE_LENGTH 512

void init_records(TempRecord **records, int *capacity) 
{
    *capacity = 10000;
    *records = malloc(*capacity * sizeof(TempRecord));
    if (!*records) 
    {
        fprintf(stderr, "Memory allocation error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void add_record_dynamic(TempRecord **records, int *size, int *capacity, TempRecord new_record) 
{
    if (*size >= *capacity) 
    {
        *capacity *= 2;
        TempRecord *temp = realloc(*records, *capacity * sizeof(TempRecord));
        if (!temp) 
        {
            fprintf(stderr, "Memory reallocation error: %s\n", strerror(errno));
            free(*records);
            exit(EXIT_FAILURE);
        }
        *records = temp;
    }
    (*records)[(*size)++] = new_record;
}

int is_valid_record(const TempRecord *r) 
{
    return (r->month >= 1 && r->month <= 12) && 
           (r->day >= 1 && r->day <= 31) &&
           (r->hour >= 0 && r->hour <= 23) &&
           (r->minute >= 0 && r->minute <= 59) &&
           (r->temperature >= -99 && r->temperature <= 99);
}

int parse_csv_line(const char *line, int line_num, TempRecord *record) 
{
    char buffer[MAX_LINE_LENGTH];
    char *endptr;
    
    strncpy(buffer, line, sizeof(buffer));
    buffer[sizeof(buffer)-1] = '\0';

    if (strlen(buffer) == 0 || strspn(buffer, " \t\r\n") == strlen(buffer)) 
    {
        return 0; 
    }

    int field_count = 0;
    const char *ptr = buffer;
    while (*ptr) if (*ptr++ == ';') field_count++;
    if (field_count != 5) 
    {
        fprintf(stderr, "Error in line %d: expected 5 fields, got %d\n", line_num, field_count + 1);
        return 0;
    }

    record->year = strtol(buffer, &endptr, 10);
    if (*endptr != ';') 
    {
        fprintf(stderr, "Error in line %d: invalid year format\n", line_num);
        return 0;
    }
    
    record->month = strtol(endptr + 1, &endptr, 10);
    if (*endptr != ';') 
    {
        fprintf(stderr, "Error in line %d: invalid month format\n", line_num);
        return 0;
    }
    
    record->day = strtol(endptr + 1, &endptr, 10);
    if (*endptr != ';') 
    {
        fprintf(stderr, "Error in line %d: invalid day format\n", line_num);
        return 0;
    }
    
    record->hour = strtol(endptr + 1, &endptr, 10);
    if (*endptr != ';') 
    {
        fprintf(stderr, "Error in line %d: invalid hour format\n", line_num);
        return 0;
    }
    
    record->minute = strtol(endptr + 1, &endptr, 10);
    if (*endptr != ';') 
    {
        fprintf(stderr, "Error in line %d: invalid minute format\n", line_num);
        return 0;
    }
    
    record->temperature = strtol(endptr + 1, &endptr, 10);
    if (*endptr != '\0' && !isspace(*endptr)) 
    {
        fprintf(stderr, "Error in line %d: invalid temperature format\n", line_num);
        return 0;
    }

    return is_valid_record(record);
}

int load_from_csv(const char *filename, TempRecord **records, int *size, int *capacity) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        fprintf(stderr, "Error: Cannot open file '%s' (%s)\n", filename, strerror(errno));
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    int error_count = 0;
    
    printf("Loading data from %s...\n", filename);
    
    while (fgets(line, sizeof(line), file) && *size < 1000000) 
    {
        line_num++;
        line[strcspn(line, "\r\n")] = '\0';

        if (line_num == 1) continue; 

        TempRecord temp;
        if (!parse_csv_line(line, line_num, &temp)) 
        {
            if (strlen(line) > 0) 
            { 
                fprintf(stderr, "Error in line %d: %s\n", line_num, line);
                error_count++;
            }
            continue;
        }

        add_record_dynamic(records, size, capacity, temp);
    }

    fclose(file);
    
    printf("--------------------------------\n");
    printf("Total lines processed: %d\n", line_num-1);
    printf("Valid records loaded:  %d\n", *size);
    printf("Errors detected:       %d\n", error_count);
    printf("--------------------------------\n");
    
    if (*size == 0) 
    {
        fprintf(stderr, "Error: No valid records found in file\n");
        return 0;
    }
    
    return 1;
}

int compare_records(const void *a, const void *b) 
{
    const TempRecord *r1 = (const TempRecord *)a;
    const TempRecord *r2 = (const TempRecord *)b;
    
    if (r1->year != r2->year) return r1->year - r2->year;
    if (r1->month != r2->month) return r1->month - r2->month;
    if (r1->day != r2->day) return r1->day - r2->day;
    if (r1->hour != r2->hour) return r1->hour - r2->hour;
    return r1->minute - r2->minute;
}

void sort_records(TempRecord records[], int size) 
{
    if (size > 1) 
    {
        qsort(records, size, sizeof(TempRecord), compare_records);
    }
}

void print_record(const TempRecord *record) 
{
    printf("%04d-%02d-%02d %02d:%02d | %+4d C\n",
           record->year, record->month, record->day,
           record->hour, record->minute, record->temperature);
}

void print_records(TempRecord records[], int size) 
{
    if (size == 0) {
        printf("No records available\n");
        return;
    }
    
    printf("Date       Time  | Temperature\n");
    printf("-----------------------------\n");
    for (int i = 0; i < size; i++) 
    {
        print_record(&records[i]);
    }
    printf("-----------------------------\n");
}

void print_records_by_month(TempRecord records[], int size, int month) 
{
    if (month < 1 || month > 12) {
        printf("Invalid month number\n");
        return;
    }
    
    const char *months[] = {"January","February","March","April","May","June",
                           "July","August","September","October","November","December"};
    
    printf("\nRecords for %s:\n", months[month-1]);
    printf("-----------------------------\n");
    
    int found = 0;
    for (int i = 0; i < size; i++) 
    {
        if (records[i].month == month) 
        {
            print_record(&records[i]);
            found = 1;
        }
    }
    
    if (!found) 
    {
        printf("No records found for this month\n");
    }
    printf("-----------------------------\n");
}

void print_monthly_stats(TempRecord records[], int size, int month) 
{
    if (month < 1 || month > 12) {
        printf("Invalid month number\n");
        return;
    }
    
    const char *months[] = {"January","February","March","April","May","June",
                           "July","August","September","October","November","December"};
    
    printf("\nMonthly Statistics for %s\n", months[month-1]);
    printf("================================\n");
    
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
        printf("No data available for this month\n");
    }
    else 
    {
        printf("Records count:    %8d\n", count);
        printf("Average temp:     %+8.1f C\n", (float)sum/count);
        printf("Minimum temp:     %+8d C\n", min);
        printf("Maximum temp:     %+8d C\n", max);
    }
    printf("================================\n");
}

void print_yearly_stats(TempRecord records[], int size) 
{
    printf("\nYearly Statistics\n");
    printf("================================\n");
    
    if (size == 0) 
    {
        printf("No data available\n");
    }
    else 
    {
        int sum = 0, min = 100, max = -100;
        for (int i = 0; i < size; i++) 
        {
            int t = records[i].temperature;
            sum += t;
            if (t < min) min = t;
            if (t > max) max = t;
        }
        
        printf("Records count:    %8d\n", size);
        printf("Average temp:     %+8.1f C\n", (float)sum/size);
        printf("Minimum temp:     %+8d C\n", min);
        printf("Maximum temp:     %+8d C\n", max);
    }
    printf("================================\n");
}