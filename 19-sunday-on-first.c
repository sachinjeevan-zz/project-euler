/* How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 */

#include <stdio.h>

int is_leap_year(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int solve()
{
    int weekday;
    int year, month;
    int count = 0;
    year = 1900;
    month = 1;
    weekday = 1;
    while (year < 2001) {
        int dayofmonth;
        if (weekday == 0 && year >= 1901) {
            count++;
        }
        switch (month) {
            case 4:
            case 6:
            case 9:
            case 11:
                dayofmonth = 30;
                break;
            case 2:
                if (is_leap_year(year))
                    dayofmonth = 29;
                else
                    dayofmonth = 28;
                break;
            default:
                dayofmonth = 31;
        }
        weekday = (weekday + dayofmonth) % 7;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return count;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
