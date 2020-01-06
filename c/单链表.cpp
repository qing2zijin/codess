* ������* /

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node, * linklist;

linklist create_linklist(linklist, int); //��������
void Getelem(linklist, int);              //����
void search_elem(linklist, int);		  //����
linklist list_delete(linklist, int);       //ɾ�����еĵ�n��Ԫ��

int main(void)
{
	int n;
	int i;
	linklist  L = (linklist)malloc(sizeof(Node));	/*��ʼ��*/
	L->next = NULL;

	printf("����Ҫ���������Ƕ��٣�");
	scanf_s("%d", &n);

	create_linklist(L, n);       //���봴������
	Getelem(L, n);               //��������
	search_elem(L, 3);           //���ұ��е�����Ԫ��

	printf("��������ɾ���ڼ���Ԫ�أ�");
	scanf_s("%d", &i);
	list_delete(L, i);

	Getelem(L, n - 1);
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
		Ptail = p;         //�����Ľ�㶼�ᱻ�滻��β���
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
	printf("�����еĸ�Ԫ��Ϊ��");
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

linklist list_delete(linklist L, int n)
{
	linklist p = L;
	int i = 1;
	while (p && i < n)        //��������n������ǰһ����㣬����Ҫɾ���Ľ���ǰһ����㡣
	{
		p = p->next;
		++i;
	}
	if (!(p->next) && i > n)
		printf("ERROR\n");

	linklist q = p->next;     //q������p����p->next->next�䣬��p->next��ֵ��q���򻯺�������
	p->next = q->next;		 //��q�ĺ�̸�ֵ��p�ĺ�̣��ƹ�q��㣬�����ߡ����ӡ�
	free(q);				 //��ϵͳ���մ˽��q���ͷ��ڴ�

	return L;
}


/*  ��ͷ�巨��
��Ϊ���Ľ�㸳ֵ���������룩��
4 5 6 9 5
�����и���Ԫ��Ϊ�� 5 9 6 5 4
-------------------------------
ͨ��vs2019��д��2020/1/5
-------------------------------
*/

/*��β�巨��
��Ϊ���Ľ�㸳ֵ���������룩��
1 2 3 4 5
β����������Ϊ5
�����и���Ԫ��Ϊ�� 1 2 3 4 5
--------------------------------
ͨ��vs2019��д��2020/1/5
--------------------------------
*/

/* ���� ����
����Ҫ���������Ƕ��٣�5
��Ϊ���Ľ�㸳ֵ��
12 3 4 5 6
�����и���Ԫ��Ϊ�� 12 3 4 5 6
������Ԫ��Ϊ4
*/

/* ��ɾ����㣩
����Ҫ���������Ƕ��٣�5
��Ϊ���Ľ�㸳ֵ��
45 2 31 3 19
�����еĸ�Ԫ��Ϊ�� 45 2 31 3 19
������Ԫ��Ϊ31
��������ɾ���ڼ���Ԫ�أ�3
�����еĸ�Ԫ��Ϊ�� 45 2 3 19
*/

/**
*β�巨���ã�ͷ�巨��������ǵ���ģ��������ݴ����ø��鷳�� 2020/1/6
*/