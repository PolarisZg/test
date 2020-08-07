#include<stdio.h>

int main()
{
    int a[10][10], b[10], c[10];
    int n, x, i, j, t;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf_s("%d", &a[i][j]);
    for (i = 0; i < n; i++)
    {
        c[i] = 0;
        b[i] = a[i][0];
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
        {
            if (a[i][j + 1] < a[i][j])
            {
                c[i] = j + 1;
                b[i] = a[i][j + 1];
            }
        }
    t = b[0]; x = 0;
    for (i = 0; i < n - 1; i++)
        if (b[i + 1] > b[i])
        {
            x = i + 1;
            t = b[i + 1];
        }
    printf("%d %d %d", t, x, c[x]);
    return 0;
}