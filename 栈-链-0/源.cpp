#include<stdio.h>
#include<stdlib.h>
typedef struct ELEM
{

}Elemtype;
typedef struct LINKLIST
{
	Elemtype elem;
	struct LINKLIST* next;
}LinkList,* Plist;
void STRACK_INI(Plist* L)
{
	(*L)->next == NULL;
}
int STRACK_EMPTY(Plist L)
{
	if (L->next == NULL)
		return 1;//Пе
	return 0;
}
int STRACK_PUSH(Plist* L, Elemtype e)
{
	Plist p = NULL;

}
int STRACK_POP
int main()
{
	Plist head;
}