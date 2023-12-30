#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};

int isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) 
{
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

struct Date addDays(struct Date date, int numDays) {
    date.day += numDays;
    while (date.day > daysInMonth(date.month, date.year)) {
        date.day -= daysInMonth(date.month, date.year);
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
    }
    return date;
}

int main() {
    struct Date today;
    printf("Enter today's date (dd mm yyyy): ");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    int daysToAdd;
    printf("Enter the number of days to add: ");
    scanf("%d", &daysToAdd);

    struct Date newDate = addDays(today, daysToAdd);

    printf("Today's date: %02d-%02d-%04d\n", today.day, today.month, today.year);
    printf("New date after adding %d days: %02d-%02d-%04d\n", daysToAdd, newDate.day, newDate.month, newDate.year);

    return 0;
}