/*单链表*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


/*线性表的单链表存储结构*/
typedef struct Node
{
	int data;         //数据域
	struct Node* next; //指针域
}Node, *linklist;

/*创建链表(头插法)，并产生n个元素的值*/
linklist creat_linklist(linklist,int);
void Getelem(linklist,int); //读取单链表

int main(void)
{
	Node L;
	creat_linklist(&L, 5);
	Getelem(&L,5);

	return 0;
}

linklist creat_linklist(linklist L,int n)
{
	linklist p;  //小结点
	int i, val;

	/*1.先建立一个带头结点的单链表*/
	 L = (linklist)malloc(sizeof(Node));
	if (NULL == L)
	{
		printf("分配失败！\n");
		exit(-1);
	}
	L->next = NULL;

	/*2.在之前的基础上插入结点*/
	printf("请为您的结点赋值，中间用空格隔开：");
	for (i = 0; i < n; ++i)
	{
		p = (linklist)malloc(sizeof(Node)); //生成新结点
		scanf_s("%d ", &val); 
		p->data = val;
		
		p->next = L->next;
		L->next = p;  //插入到表头
	}
	return L;
}

void Getelem(linklist L,int i)
{
	int j;
	linklist p;				//声明一结点p
	p = L->next;			//让p指向链表L的第一个结点
	printf("元素为：");
	j = 1;
	while (p && j < i)		//p不为空且j<iS
	{
		
		p = p->next;		//让p指向下一结点
		printf("%d", p->data);
		++j;
	}
	if (!p || j > i)
		printf("ERROR!\n");

	return;
}