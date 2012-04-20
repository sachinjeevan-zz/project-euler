/* Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 28183

int sum_of_divisors(int n)
{
    int i;
    int sum = 1;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return sum;
}

int solve()
{
    int abundant_map[LIMIT] = {0};
    int map[LIMIT] = {0}; /* whether a num can be written as sum of abundant */
    int i, j, ret;

    /* prepare abundant-map */
    for (i = 1; i < LIMIT; i++) {
        if (sum_of_divisors(i) > i) {
            abundant_map[i] = 1;
        }
    }

    for (i = 1; i < LIMIT / 2; i++) {
        if (!abundant_map[i])
            continue;
        for (j = i; j < LIMIT && i + j < LIMIT; j++)
            if (abundant_map[j])
                map[i + j] = 1;
    }

    ret = 0;
    for (i = 1; i < LIMIT; i++)
        if (!map[i])
            ret += i;
    return ret;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
