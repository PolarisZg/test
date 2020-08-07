#include<stdio.h>
#include<stdlib.h>
//表达式转换为二叉树
//首先将表达式最右端的操作符(最后进行计算的操作符)找到，把他定义为表达式所在子树的根节点
//然后将表达式分为两部分，左边为左子树，右边为右子树

typedef struct Data
{
	int type = 0;//类型，如果是运算符则为0，是数字则为1；
	float num = 0;
	char c = '\0';
}Data;
typedef struct TREE
{
	Data data;
	struct TREE* Lchild = NULL;
	struct TREE* Rchild = NULL;
}Tree,* Ptree;

//表达式输入
int In(Data* data)
{
	char s[100];
	gets_s(s);
	int length = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		int temp = 0;
		if (s[i] >= '0' && s[i] <= '9')//获取数字
		{
			temp = s[i] - '0';
			while (s[i + 1] != '\0')
			{
				if (s[i + 1] >= '0' && s[i + 1] <= '9')//下一位依然是数字
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

//*s表达式，head表达式头字符所在数组下标，tail表达式尾字符所在数组下标加一
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
		//括号问题
		int n = 0;//记录括号
		int location_add = 0;//记录加减法位置
		int location_muti = 0;//记录乘除法位置

		for (int i = head; i < tail; i++)
		{
			if (data[i].type == 0)
			{
				if (data[i].c == '(' || data[i].c == '（')
					n = 1;
				if (data[i].c == ')' || data[i].c == '）')
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
			return CreatTree(data, head + 1, tail - 1);//整个式子被括号包起来了
		else
		{
			if (location_add > 0)//式子最后计算的是加减，所以先考虑加减号
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
	printf("=%.2f(保留两位小数）", answer);
}