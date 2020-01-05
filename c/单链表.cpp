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
void search_elem(linklist, int);


int main(void)
{
	int n;
	linklist  L = (linklist)malloc(sizeof(Node));	/*初始化*/
	L->next = NULL;

	printf("您想要的链表长度是多少？");
	scanf_s("%d", &n);

	create_linklist(L, n);/*插入创建链表*/
	Getelem(L, n);         /*遍历链表*/
	search_elem(L, 3);     /*查找表中第三个元素*/

	return 0;
}
/*
linklist create_linklist(linklist L, int n) //头插法：后来先到
{
	int val;
	printf("请为您的结点赋值：\n");
	for (int i = 0; i< n; ++i)
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
*/
/*尾插法，先来后到*/
linklist create_linklist(linklist L, int n)
{
	int val;
	linklist Ptail = L;			//创建一个尾结点

	printf("请为您的结点赋值：\n");
	for (int i = 0; i < n; ++i)
	{
		linklist p = (linklist)malloc(sizeof(Node));
		scanf_s("%d", &val);
		if (NULL == p)
			exit(-1);
		p->data = val;
		p->next = NULL;
		Ptail->next = p;
		Ptail = p;     //新来的结点都会被替换成尾结点
	}
	/*printf("尾结点的数据域为%d\n", Ptail->data);*/
	Ptail->next = NULL;
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
	printf("\n");
	return;
}

void search_elem(linklist L, int n)
{
	linklist p = L;
	int i = 1;
	while (p && i <= n)
	{
		p = p->next;
		++i;
	}
	printf("第三个元素为%d\n", p->data);
	return;
}


/*  （头插法）
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

/*（尾插法）
请为您的结点赋值（换行输入）：
1
2
3
4
5
尾结点的数据域为5
元素为： 1 2 3 4 5
--------------------------------
通过vs2019编写，2020/1/5
--------------------------------
*/

/* 遍历 查找
您想要的链表长度是多少？5
请为您的结点赋值：
12 3 4 5 6
元素为： 12 3 4 5 6
第三个元素为4
--------------------------------
通过vs2019编写，2020/1/5
--------------------------------
*/