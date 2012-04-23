/* Find the sum of all the numbers that can be written as the sum of fifth
 * powers of their digits.
 */

#include <stdio.h>
#include <math.h>

int sum_digit_power(int n, int power)
{
    int sum = 0;
    while (n > 0) {
        sum += (int)pow(n % 10, power);
        n /= 10;
    }
    return sum;
}

int solve()
{
    int i;
    int ret = 0;
    for (i = 2; i < 1000000; i++)
        if (i == sum_digit_power(i, 5)) {
            ret += i;
            printf("equal: %d\n", i);
        }
    return ret;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
