/* Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 28183

/* sum of all divisors, including n itself */
int sum_of_divisors(int n)
{
    int sum = 1;
    int i;
    for (i = 2; i * i <= n; i++) {
        int p = 1;
        while (n % i == 0) {
            p = p * i + 1;
            n /= i;
        }
        printf("*%d\n", p);
        sum *= p;
    }
    /* if n is > 1 here, the remaining n is also a divisor of the original
     * number */
    if (n > 1)
        sum *= n + 1;
    return sum;
}

int solve()
{
    int abundant_map[LIMIT] = {0};
    int map[LIMIT] = {0}; /* whether a num can be written as sum of abundant */
    int i, j, ret;

    /* prepare abundant-map */
    for (i = 1; i < LIMIT; i++) {
        if (sum_of_divisors(i) > 2*i) {
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
    //printf("%d\n", solve());
    printf("sum of divisors 12: %d\n", sum_of_divisors(12));
    return 0;
}
