/* Discover all the fractions with an unorthodox cancelling method.
 */

#include <stdio.h>

void solve()
{
    int n, d;
    for (n = 10; n < 100; n++) {
        for (d = n + 1; d < 100; d++) {
            int nn[2] = {n / 10, n % 10};
            int dd[2] = {d / 10, d % 10};
            int i, j;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    if (nn[i] != dd[j] && nn[1-i] == dd[1-j] && nn[1-i] && dd[1-j] && nn[i] * d == dd[j] * n)
                        printf("%d/%d = %d/%d\n", n, d, nn[i], dd[j]);
        }
    }
}

int main()
{
    solve();
    return 0;
}

