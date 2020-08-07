#include<stdio.h>
#include<stdlib.h>
typedef struct Item
{
	char* Name = NULL;
	int Num = 0;
	int** Date = NULL;
}Item;
typedef struct Player
{
	int* JoinItem = NULL;
	int JoinItem_Num;
}Player;
typedef struct Queue
{
	int elme;
	struct Queue* next;
}Queue,* Pqueue;
typedef struct 
{
	Pqueue Front = NULL;
	Pqueue Rear = NULL;
}squeue;
void Queue_En(squeue* s, int elme)
{
	Queue* p = NULL;
	p = (Queue*)malloc(sizeof(Queue));
	p->elme = elme;
	Queue* q = s->Rear;
	p->next = q->next;
	q->next = p;
	s->Rear = p;
}
int Queue_De(squeue* s)
{
	int elme = s->Front->next->elme;
	Queue* p = s->Front->next;
	s->Front->next = p->next;
	free(p);
	return elme;
}
void Sport_Iniqueue(squeue* s, int size)
{
	s->Front = (Queue*)malloc(sizeof(Queue));
	s->Rear = (Queue*)malloc(sizeof(Queue));
	s->Rear = s->Front;
	s->Front->next = NULL;
	for (int i = 0; i < size; i++)
	{
		Queue_En(s, i);
	}
}
void Sport_Item(Item* item)
{
	printf("输入运动会项目种类数:");
	scanf_s("%d", &((*item).Num));
	(item->Name) = (char*)malloc(sizeof(char) * (item->Num));
	item->Date = (int**)malloc(sizeof(int*) * (item->Num));
	for (int i = 0; i < item->Num; i++)
	{
		item->Name[i] = 'A' + i;
		printf("%c:%d\n", item->Name[i], i);
		item->Date[i] = (int*)malloc(sizeof(int) * (item->Num));
		for (int j = 0; j < item->Num; j++)
			item->Date[i][j] = 0;
	}
}
void Sport_Player(Player* player, int player_Num, Item* item)
{
	char c;
	int j;
	for (int i = 0; i < player_Num; i++)
	{
		printf("输入第%d个学生的参赛项目，以#结束:", i + 1);
		player[i].JoinItem = (int*)malloc(sizeof(int));
		c = '\0';
		for (j = 0; c != '#'; c = getchar())
			if (c >= '0' && c <= '9')
			{
				player[i].JoinItem[j] = c - '0';
				j++;
			}
		player[i].JoinItem_Num = j;
		for (j = 0; j < player[i].JoinItem_Num; j++)
			for (int k = 0; k < player[i].JoinItem_Num; k++)
				item->Date[player[i].JoinItem[j]][player[i].JoinItem[k]] = 1;
	}
}
void Sport_Timetable(Item item, squeue* s)
{
	int elme;
	int i;
	int* a;
	a = (int*)malloc(sizeof(int) * item.Num);
	Queue* p;
	while (s->Front->next != NULL && s->Front->next != s->Rear)
	{
		for (int j = 0; j < item.Num; j++)
			a[j] = 0;
		elme = Queue_De(s);
		for (int j = 0; j < item.Num; j++)
			if (item.Date[elme][j] == 0)
				a[j] = 1;
		p = s->Rear;
		printf("%d ", elme);
		while (s->Front->next != NULL && s->Front->next != p)
		{
			i = Queue_De(s);
			if (a[i] == 1)
			{
				printf("%d ", i);
				for (int j = 0; j < item.Num; j++)
					if (item.Date[i][j] == 1)
						a[j] = 0;
			}
			else
				Queue_En(s, i);
		}
		i = p->elme;
		if (a[i] == 1)
		{
			s->Front->next = p->next;
			free(p);
			printf("%d ", i);
			for (int j = 0; j < item.Num; j++)
				if (item.Date[i][j] == 1)
					a[j] = 0;
		}
		printf("\n");
	}
}
int main()
{
	Item item;
	squeue s;
	Player* player = NULL;
	int player_Num;
	Sport_Item(&item);
	printf("输入参赛学生人数: ");
	scanf_s("%d", &player_Num);
	player = (Player*)malloc(sizeof(Player) * player_Num);
	Sport_Player(player, player_Num, &item);
	Sport_Iniqueue(&s, item.Num);
	Sport_Timetable(item, &s);
}