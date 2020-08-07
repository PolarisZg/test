#include<stdio.h> 
int main()
{
    char str[10][21]; char c;
    int n, i, j, t;
    int a[10][21] = {};
    scanf_s("%d", &n);
    for (i = 0; i < n; i++)
        scanf_s("%s", str[i]);
    for (i = 0; i < n; i++)
        for (j = 0; (c = str[i][j]) != '\0'; j++)
        {
            switch (c)
            {
            case 'V':t = 1; break;
            case 'Z':t = 2; break;
            case 'T':t = 3; break;
            case 'L':t = 4; break;
            case 'N':t = 5; break;
            case 'R':t = 6; break;
            default:t = 0;
            }
            a[i][j] = t;
        }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 21; j++)
        {
            if (a[i][j] != 0 && a[i][j] != a[i][j + 1])
                printf("%d", a[i][j]);

        }
        printf("\n");
    }
    return 0;
}