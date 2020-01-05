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
void search_elem(linklist, int);


int main(void)
{
	int n;
	linklist  L = (linklist)malloc(sizeof(Node));	/*��ʼ��*/
	L->next = NULL;

	printf("����Ҫ���������Ƕ��٣�");
	scanf_s("%d", &n);

	create_linklist(L, n);/*���봴������*/
	Getelem(L, n);         /*��������*/
	search_elem(L, 3);     /*���ұ��е�����Ԫ��*/

	return 0;
}
/*
linklist create_linklist(linklist L, int n) //ͷ�巨�������ȵ�
{
	int val;
	printf("��Ϊ���Ľ�㸳ֵ��\n");
	for (int i = 0; i< n; ++i)
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
*/
/*β�巨��������*/
linklist create_linklist(linklist L, int n)
{
	int val;
	linklist Ptail = L;			//����һ��β���

	printf("��Ϊ���Ľ�㸳ֵ��\n");
	for (int i = 0; i < n; ++i)
	{
		linklist p = (linklist)malloc(sizeof(Node));
		scanf_s("%d", &val);
		if (NULL == p)
			exit(-1);
		p->data = val;
		p->next = NULL;
		Ptail->next = p;
		Ptail = p;     //�����Ľ�㶼�ᱻ�滻��β���
	}
	/*printf("β����������Ϊ%d\n", Ptail->data);*/
	Ptail->next = NULL;
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
	printf("������Ԫ��Ϊ%d\n", p->data);
	return;
}


/*  ��ͷ�巨��
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

/*��β�巨��
��Ϊ���Ľ�㸳ֵ���������룩��
1
2
3
4
5
β����������Ϊ5
Ԫ��Ϊ�� 1 2 3 4 5
--------------------------------
ͨ��vs2019��д��2020/1/5
--------------------------------
*/

/* ���� ����
����Ҫ���������Ƕ��٣�5
��Ϊ���Ľ�㸳ֵ��
12 3 4 5 6
Ԫ��Ϊ�� 12 3 4 5 6
������Ԫ��Ϊ4
--------------------------------
ͨ��vs2019��д��2020/1/5
--------------------------------
*/