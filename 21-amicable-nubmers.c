/* Evaluate the sum of all the amicable numbers under 10000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_divisors_sum(int n)
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

int solve(int n)
{
    int *map;
    int i;
    int sum = 0;

    map = calloc(sizeof(int), n);
    for (i = 2; i < n; i++)
        map[i] = get_divisors_sum(i);
    for (i = 2; i < n; i++)
        if (map[i] < n && map[i] > 1 && i != map[i] && map[map[i]] == i) {
            printf("%d-%d\n", i, map[i]);
            sum += i;
        }
    free(map);
    return sum;
}

int main()
{
    printf("%d\n", solve(10000));
    return 0;
}
