#include<stdio.h>
#include<stdlib.h>
//���ʽת��Ϊ������
//���Ƚ����ʽ���Ҷ˵Ĳ�����(�����м���Ĳ�����)�ҵ�����������Ϊ���ʽ���������ĸ��ڵ�
//Ȼ�󽫱��ʽ��Ϊ�����֣����Ϊ���������ұ�Ϊ������

typedef struct Data
{
	int type = 0;//���ͣ�������������Ϊ0����������Ϊ1��
	float num = 0;
	char c = '\0';
}Data;
typedef struct TREE
{
	Data data;
	struct TREE* Lchild = NULL;
	struct TREE* Rchild = NULL;
}Tree,* Ptree;

//���ʽ����
int In(Data* data)
{
	char s[100];
	gets_s(s);
	int length = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		int temp = 0;
		if (s[i] >= '0' && s[i] <= '9')//��ȡ����
		{
			temp = s[i] - '0';
			while (s[i + 1] != '\0')
			{
				if (s[i + 1] >= '0' && s[i + 1] <= '9')//��һλ��Ȼ������
				{
					temp = temp * 10 + (s[i + 1] - '0');
					i++;
				}
				else
					break;
			}
			data[length].type = 1;
			data[length].num = temp;
			length++;
		}
		else
		{
			data[length].type = 0;
			data[length].c = s[i];
			length++;
		}
	}
	return length;
}

//*s���ʽ��head���ʽͷ�ַ����������±꣬tail���ʽβ�ַ����������±��һ
Ptree CreatTree(Data* data, int head, int tail)
{
	if (tail - head == 1)
	{
		Ptree t = NULL;
		t = (Tree*)malloc(sizeof(Tree));
		t->Lchild = t->Rchild = NULL;
		t->data = data[head];
		return t;
	}
	else
	{
		//��������
		int n = 0;//��¼����
		int location_add = 0;//��¼�Ӽ���λ��
		int location_muti = 0;//��¼�˳���λ��

		for (int i = head; i < tail; i++)
		{
			if (data[i].type == 0)
			{
				if (data[i].c == '(' || data[i].c == '��')
					n = 1;
				if (data[i].c == ')' || data[i].c == '��')
					n = 0;
				if (n == 0)
				{
					if (data[i].c == '+' || data[i].c == '-')
						location_add = i;
					if (data[i].c == '*' || data[i].c == '/')
						location_muti = i;
				}
			}
		}

		if (location_add == 0 && location_muti == 0)
			return CreatTree(data, head + 1, tail - 1);//����ʽ�ӱ����Ű�������
		else
		{
			if (location_add > 0)//ʽ����������ǼӼ��������ȿ��ǼӼ���
			{
				Ptree t = NULL;
				t = (Tree*)malloc(sizeof(Tree));
				t->data = data[location_add];
				t->Lchild = CreatTree(data, head, location_add);
				t->Rchild = CreatTree(data, location_add + 1, tail);
				return t;
			}
			else
			{
				Ptree t = NULL;
				t = (Tree*)malloc(sizeof(Tree));
				t->data = data[location_muti];
				t->Lchild = CreatTree(data, head, location_muti);
				t->Rchild = CreatTree(data, location_muti + 1, tail);
				return t;
			}
		}
	}
}

float T_answer(Ptree t)
{
	if (t->Lchild == NULL && t->Rchild == NULL)
		return t->data.num;
	else
	{
		float Lanswer = T_answer(t->Lchild);
		float Ranswer = T_answer(t->Rchild);
		switch (t->data.c)
		{
		case '+':return (Lanswer + Ranswer);
		case'-':return (Lanswer - Ranswer);
		case'*':return (Lanswer * Ranswer);
		case'/':return(Lanswer / Ranswer);
		}
	}
}

int main()
{
	int length = 0;
	Data data[200];
	length = In(data);
	Ptree t = CreatTree(data, 0, length);
	float answer = T_answer(t);
	printf("=%.2f(������λС����", answer);
}