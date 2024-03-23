/*
A modified version of PC200657 exercise using arrays.
*/

#include <stdio.h>
#include <stdlib.h>

int isLeap (int year) {
    
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
}

int which_day(int year, int month, int day) {

    int days_in_month[] = {0, 31, isLeap(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = day;

    for(int i = 1; i < month; i++)
        days += days_in_month[i];

    return days;

}


int next_arrival(int year, int month, int day) {

    int day_of_today = which_day(year, month, day);

    // 6th of December has already passed, we wait till next year
    if(month == 12 && day > 6) {
        int day_of_santa = which_day(year + 1, 12, 6);
        return 31 - day + day_of_santa;
    } else {
        int day_of_santa = which_day(year, 12, 6);
        return day_of_santa - day_of_today;
    }
}


int main() {

    int year, month, day;
    int next_arrival(int, int, int);
    while (scanf("%d %d %d", &year, &month, &day) != EOF)
    {
        int res = next_arrival(year, month, day);
        printf("%d\n", res);
    }
    
    return EXIT_SUCCESS;

}