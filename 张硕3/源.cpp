#include <stdio.h>
#include <math.h>
int main()
{
    long long int m, t;
    int k, i, x, y = 0, n = 0;
    scanf_s("%lld %lld", &m, &t);
    for (; m <= t; m = m + 1)//for (m = m + 1; m <= t; m = m + 1)
    {
        k = sqrt(m);
        for (i = 2; i <= k; i++)
            if (m % i == 0) break;//»»ÐÐ
        if (i == k + 1)//if (i >= k + 1)
        {
            x = m;
            for (n = 0; x > 0; x = x / 10)
            {
                n = n * 10;
                n = n + x % 10;
            }
            if (n == m)
            {
                if (y == 0)
                {
                    y++;
                    printf("%lld", m);
                }
                else
                {
                    printf("\n");
                    printf("%lld", m);
                }
            }
        }

    }
    return 0;
}