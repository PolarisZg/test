#include<stdio.h>
int main()
{
    int t, i, j, total = 0; double d;
    struct student
    {
        char name[20];
        char id[20];
        int a[5];
    }st;
    gets_s(st.name);
    gets_s(st.id);
    for (i = 0; i < 5; i++)
        scanf_s("%d", &st.a[i]);
    for (i = 0; i < 5; i++)
        total = total + st.a[i];
    d = (double)total;
    d = d / 5.0;
    printf("Name:%s\nID:%s\n", st.name, st.id);
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4 - i; j++)
            if (st.a[j] < st.a[j + 1])
            {
                t = st.a[j]; st.a[j] = st.a[j + 1]; st.a[j + 1] = t;

            }
    printf("Score:%d %d %d %d %d\n", st.a[0], st.a[1], st.a[2], st.a[3], st.a[4]);
    printf("average:%.2lf total:%d", d, total);
    return 0;
}