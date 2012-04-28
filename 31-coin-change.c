/* How many different ways can £2 be made using any number of coins?
 */

#include <stdio.h>

int solve(int *curr, int i, int n)
{
    int c = 0;
    if (n == 0)
        return 1;
    if (i < 0)
        return 0;
    do {
        c += solve(curr, i - 1, n);
    } while ((n -= curr[i]) >= 0);
    return c;
}

int main()
{
    int curr[] = {1, 2, 5, 10, 20, 50, 100, 200};
    printf("%d\n", solve(curr, 7, 200));
    return 0;
}
