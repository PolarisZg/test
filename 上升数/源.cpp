#include<stdio.h>
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int UPnumMAX = 1;
	int UPnum = 1;
	int num[2];//0����һ����1�浱ǰ��
	scanf_s("%d", &num[0]);
	for (int i = 1; i < n; i++)
	{
		scanf_s("%d", &num[1]);
		if (num[1] > num[0])
			UPnum++;
		else
		{
			UPnumMAX = (UPnumMAX > UPnum ? UPnumMAX : UPnum);
			UPnum = 1;
		}
		num[0] = num[1];
	}
	printf("%d", UPnumMAX);
}