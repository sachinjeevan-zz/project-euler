/* What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
 * formed in the same way?
 */

#include <stdio.h>

int solve(int n)
{
    int i;
    int ret = 1;
    for (i = 3; i <= n; i += 2) {
        ret += 4 *  i * i - 6 * (i - 1);
    }
    return ret;
}

int main()
{
    printf("%d\n", solve(5));
    return 0;
}
