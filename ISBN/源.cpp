#include<stdio.h>
#include<math.h>
int main()
{
    int i, j = 1, s = 0, n = 0;
    char c, a[14] = {};
    gets_s(a);
    for (i = 0; (c = (a[i])) != '\0'; i++)
    {
        if (c >= '0' && c <= '9')
        {
            n += (c - '0') * j;
            j++;
        }
        if (j > 9)
            break;
    }
    s = a[12] - '0';

    if (s == n % 11)
        printf("Right");
    else
        printf("%.12s%d", a, n % 11);
    return 0;
}