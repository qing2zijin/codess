/*������*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


/*���Ա�ĵ�����洢�ṹ*/
typedef struct Node
{
	int data;         //������
	struct Node* next; //ָ����
}Node, *linklist;

/*��������(ͷ�巨)��������n��Ԫ�ص�ֵ*/
linklist creat_linklist(linklist,int);
void Getelem(linklist,int); //��ȡ������

int main(void)
{
	Node L;
	creat_linklist(&L, 5);
	Getelem(&L,5);

	return 0;
}

linklist creat_linklist(linklist L,int n)
{
	linklist p;  //С���
	int i, val;

	/*1.�Ƚ���һ����ͷ���ĵ�����*/
	 L = (linklist)malloc(sizeof(Node));
	if (NULL == L)
	{
		printf("����ʧ�ܣ�\n");
		exit(-1);
	}
	L->next = NULL;

	/*2.��֮ǰ�Ļ����ϲ�����*/
	printf("��Ϊ���Ľ�㸳ֵ���м��ÿո������");
	for (i = 0; i < n; ++i)
	{
		p = (linklist)malloc(sizeof(Node)); //�����½��
		scanf_s("%d ", &val); 
		p->data = val;
		
		p->next = L->next;
		L->next = p;  //���뵽��ͷ
	}
	return L;
}

void Getelem(linklist L,int i)
{
	int j;
	linklist p;				//����һ���p
	p = L->next;			//��pָ������L�ĵ�һ�����
	printf("Ԫ��Ϊ��");
	j = 1;
	while (p && j < i)		//p��Ϊ����j<iS
	{
		
		p = p->next;		//��pָ����һ���
		printf("%d", p->data);
		++j;
	}
	if (!p || j > i)
		printf("ERROR!\n");

	return;
}