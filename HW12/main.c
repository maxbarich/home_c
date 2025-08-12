#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"

void print_help() 
{
    printf("Usage:\n");
    printf("  -h              Show help\n");
    printf("  -f <file.csv>   Load data from CSV file\n");
    printf("  -m <month>      Show stats and records for the specified month only\n");
}

int main(int argc, char *argv[]) 
{
    TempRecord records[MAX_RECORDS];
    int size = 0;

    int show_help = 0;
    char *filename = NULL;
    int filter_month = 0;

    for (int i = 1; i < argc; i++) 
    {
        if (strcmp(argv[i], "-h") == 0) 
        {
            show_help = 1;
        } 
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) 
        {
            filename = argv[++i];
        } 
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) 
        {
            filter_month = atoi(argv[++i]);
        }
    }

    if (show_help || argc == 1) 
    {
        print_help();
        return 0;
    }

    if (filename && !load_from_csv(filename, records, &size)) 
    {
        return 1;
    }

    sort_records(records, size);

    if (filter_month) 
    {
        print_records_by_month(records, size, filter_month);
        print_monthly_stats(records, size, filter_month);
    } 
    else 
    {
        print_records(records, size);
        print_yearly_stats(records, size);
    }

    return 0;
}