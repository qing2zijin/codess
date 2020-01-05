/* ������*/

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
	linklist  L = (linklist)malloc(sizeof(Node));	/*��ʼ��*/
	L->next = NULL;

	create_linklist(L, 5);/*���봴������*/
	Getelem(L, 5);         /*��������*/

	return 0;
}

linklist create_linklist(linklist L, int n) //ͷ�巨�������ȵ�
{
	int val;
	printf("��Ϊ���Ľ�㸳ֵ���������룩��\n");
	for (int i = 0; i < n; ++i)
	{
		linklist p = (linklist)malloc(sizeof(Node));     //����һ��p���
		if (NULL == p)
			exit(-1);
		scanf_s("%d", &val);
		p->data = val;          //��ֵ
		p->next = L->next;      //p������
		L->next = p;
	}
	return L;
}

void Getelem(linklist L, int i)
{
	int j = 0;
	linklist p;
	p = L->next;
	printf("Ԫ��Ϊ��");
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
��Ϊ���Ľ�㸳ֵ���������룩��
4
5
6
9
5
Ԫ��Ϊ�� 5 9 6 5 4
-------------------------------
ͨ��vs2019��д��2020/1/5
-------------------------------
*/