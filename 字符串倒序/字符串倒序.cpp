#include<stdio.h>
char* sortchar(char* s)
{
    int i, j, k;
    char a[80], b;
    for (k = 0; s[k] != '\0'; k++);
    j = 0;
    for (i = 0; i < k; i++)
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            a[j] = s[i];
            j = j + 1;
        }
    for (i = 0; i < j; i++)
        for (k = i; k < j; k++)
            if (a[i] > a[k])
            {
                b = a[i];
                a[i] = a[k];
                a[k] = b;
            }
    for (i = 0; i < j; i++)
        s[i] = a[i];
    s[i] = '\0';
    return s;
}
int main()
{
    char s[80];
    gets_s(s);
    sortchar(s);

    puts(s);
    return 0;
}