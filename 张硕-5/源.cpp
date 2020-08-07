#include<stdio.h>
#include<string.h> 
int main()
{
    int n, i, j;
    char c[200][100], a[100];
    scanf_s("%d", &n);
    getchar();//回收回车
    for (i = 0; i < n; i++)
        gets_s(c[i]);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(c[j], c[j + 1]) > 0)
            {
                strcpy_s(a, c[j]);
                strcpy_s(c[j], c[j + 1]);
                strcpy_s(c[j + 1], a);
            }
        }
    for (i = 0; i < n; i++)
        printf("%s\n", c[i]);
    return 0;
}