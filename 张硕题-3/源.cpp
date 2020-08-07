#include<stdio.h>
#include<string.h>

int main()
{
    char c[2][21]; 
    char a; 
    int i, j;
    gets_s(c[0]);
    gets_s(c[1]);
    for (i = 0; i < 2; i++)
        for (j = 0; (a = (c[i][j]) )!= '\0'; j++)
            if (a >= 97 && a <= 122)
                c[i][j] = a - 32;
    printf("%s %s", c[0], c[1]);
    if (strcmp(c[1], c[0]) == 0)
        printf(c[1]);
    else
        printf("different");


    return 0;
}