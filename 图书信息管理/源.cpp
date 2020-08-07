#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char bname[100];
	char bno[100];
}BOOK;
typedef struct{
	BOOK* elem = NULL;
	int len = 0;
	int listsize = 0;
}Sqlist;
void Initialize(Sqlist* L)/*³õÊ¼»¯¿Õ±í*/{
	printf("Length of the list:");
	scanf_s("%d", &(*L).listsize);
	(*L).elem = (BOOK*)malloc(sizeof(BOOK) * (*L).listsize);
	(*L).len = 0;
}
void Insertelem(Sqlist* L){
	int i, j, k;
	char help[2];
	while (1){
		printf("The insertion position(1¡«%d) is:", (*L).len + 1);
		scanf_s("%d", &i);
		i = i - 1;
		for (j = (*L).len; j >= i; j--)
			(*L).elem[j + 1] = (*L).elem[j];
		printf("input name and No.,space with ENTER\n");
		gets_s(help);
		gets_s((*L).elem[i].bname);
		gets_s((*L).elem[i].bno);
		printf("if continue input 2,else input 0:");
		scanf_s("%d", &k);
		(*L).len++;
		if (k == 0)
			break;
	}
}
void Out(Sqlist L){
	int i;
	for (i = 0; i < L.len; i++)
		printf("%s %s\n", L.elem[i].bname, L.elem[i].bno);
}
void Delete(Sqlist* L){
	int i, j;
	printf("The location(1¡«%d) where the data deleted is:", (*L).len);
	scanf_s("%d", &i);
	i = i - 1;
	for (j = i; j < (*L).len; j++)
		(*L).elem[j] = (*L).elem[j + 1];
	(*L).len--;
}
void Findno(Sqlist L){
	char findno[100];
	int i;
	char help[2];
	gets_s(help);
	gets_s(findno);
	for (i = 0; i <= L.len; i++)
		if (strcmp(findno, L.elem[i].bno) == 0){
			printf("%s %s\n", L.elem[i].bname, L.elem[i].bno);
			break;
		}
	if (i > L.len)
		printf("404");
}
void Findname(Sqlist* L){
	char findname[100];
	int i;
	printf("The name of the book is:");
	gets_s(findname);
	for (i = 0; i <= (*L).len; i++)
		if (strcmp(findname, (*L).elem[i].bname) == 0){
			printf("%s %s\nNo. change:", (*L).elem[i].bname, (*L).elem[i].bno);
			gets_s((*L).elem[i].bno);
			printf("%s %s\n------------\n", (*L).elem[i].bname, (*L).elem[i].bno);
			break;
		}
	if (i > (*L).len)
		printf("404");
}
int main(){
	Sqlist L;
	Initialize(&L);
	Insertelem(&L);
	Out(L);
	Insertelem(&L);
	Out(L);
	Delete(&L);
	Out(L);
	Findno(L);
	printf("The length is %d\n", L.len + 1);
	Findname(&L);
	Out(L);
	return 0;
}