/* How many letters would be needed to write all the numbers in words from 1 to
 * 1000?
 */

#include <stdio.h>

/* one, two, three, four, five, six, seven, eight, nine */
int one_digit[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
/* eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen */
int teens[9] = {6, 6, 8, 8, 7, 7, 9, 8, 8};
/* ten, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety */
int ten_multiple[9] = {3, 6, 6, 5, 5, 5, 7, 6, 6};

int sum(int *a, int n)
{
    int ret = 0;
    while (n--)
        ret += a[n];
    return ret;
}

int letter_count(int n)
{
    /* 1 - 9 */
    if (n <= 9)
        return one_digit[n - 1];
    /* 11 - 19 */
    if (n >= 11 && n <= 19)
        return teens[n - 11];
    /* 10, 20, ... 90 */
    if (n < 100 && (n % 10 == 0))
        return ten_multiple[n / 10 - 1];
    /* 21, 22, 23 ... 99 */
    if (n < 100)
        return letter_count(n - n % 10) + letter_count(n % 10);
    /* 100, 200, ... 900 */
    if (n % 100 == 0)
        return letter_count(n / 100) + 7;
    /* 101, 102 ... 999. x hundred and xx */
    return letter_count(n / 100) + 10 + letter_count(n % 100);
}

int solve(int m, int n)
{
    int i;
    int ret = 0;
    for (i = m; i <= n; i++) {
        int j = letter_count(i);
        //printf("%d, %d\n", i, j);
        ret += j;
    }
    return ret;
}
int solve1()
{
    int one_to_9;
    int eleven_to_19;
    int one_to_99;
    int hundres;
    int one_to_999;

    one_to_9 = sum(one_digit, 9);
    eleven_to_19 = sum(teens, 9);

    one_to_99 = ten_multiple[0] + 10 * sum(ten_multiple + 1, 8) + eleven_to_19 + 9 * one_to_9;
    /* 100, 200... 900 */
    hundres = one_to_9 + 9 * 7;
    /* 3: "and". 7: "hundred" */
    one_to_999 = 10 * one_to_99 + (one_to_9 + 9 * 10) * 99 + hundres;
    return one_to_999 + 11; /* "one thousand" */
}

int main()
{
    printf("%d\n", solve1());
    puts("-----");
    printf("%d\n", solve(1, 999) + 11);
    return 0;
}
