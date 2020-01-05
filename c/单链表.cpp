/* 单链表*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node, * linklist;

linklist create_linklist(linklist, int);
void Getelem(linklist, int);

int main(void)
{
	linklist  L = (linklist)malloc(sizeof(Node));	/*初始化*/
	L->next = NULL;

	create_linklist(L, 5);/*插入创建链表*/
	Getelem(L, 5);         /*遍历链表*/

	return 0;
}

linklist create_linklist(linklist L, int n) //头插法：后来先到
{
	int val;
	printf("请为您的结点赋值（换行输入）：\n");
	for (int i = 0; i < n; ++i)
	{
		linklist p = (linklist)malloc(sizeof(Node));     //分配一个p结点
		if (NULL == p)
			exit(-1);
		scanf_s("%d", &val);
		p->data = val;          //赋值
		p->next = L->next;      //p结点插入
		L->next = p;
	}
	return L;
}

void Getelem(linklist L, int i)
{
	int j = 0;
	linklist p;
	p = L->next;
	printf("元素为：");
	while (p && j < i)
	{
		printf("% d", p->data);
		p = p->next;
		++j;
	}
	if (!p || j >= i)
		exit(-1);

	return;
}


/*
请为您的结点赋值（换行输入）：
4
5
6
9
5
元素为： 5 9 6 5 4
-------------------------------
通过vs2019编写，2020/1/5
-------------------------------
*/