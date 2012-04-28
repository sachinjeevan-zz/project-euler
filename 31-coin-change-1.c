/* How many different ways can £2 be made using any number of coins?
 */

#include <stdio.h>
#include <stdlib.h>

int solve(int *curr, int i, int n, int *table, int length)
{
    int c = 0;
    int p;
    if (n == 0)
        return 1;
    if (i < 0)
        return 0;
    p = i * length + n;
    if (table[p] > 0)
        return table[p];
    do {
        c += solve(curr, i - 1, n, table, length);
    } while ((n -= curr[i]) >= 0);
    table[p] = c;
    return c;
}

int main()
{
    int curr[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int m = 8;
    int n = 1000;
    int *table = calloc(m * (n + 1), sizeof(int));
    printf("%d\n", solve(curr, m - 1, n, table, n));
    return 0;
}
