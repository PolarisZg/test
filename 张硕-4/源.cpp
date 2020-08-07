#include<stdio.h>
#include<string.h>

int main()
{
    int t, n, i, j, k, m;
    char l, c[27];
    char a[100][30], b[100][30];
    scanf_s("%d", &t);
    for (k = 0; k < t; k++)
    {
        getchar();
        gets_s(c);
        scanf_s("%d", &n);
        getchar();
        for (i = 0; i < n; i++)
            gets_s(a[i]);

        for (i = 0; i < n; i++)
            for (j = 0; (l = a[i][j]) != '\0'; j++)
            {
                m = (int)l;
                b[i][j] = c[m - 65];
            }
        for (i = 0; i < n; i++)
        {

            for (j = 0; b[i][j]>='A'&&b[i][j]<='Z'; j++)
                printf("%c", b[i][j]);
            printf("\n");
        }
    }




    return 0;
}