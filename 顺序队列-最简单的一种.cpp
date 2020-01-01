
/*��򵥵�һ��˳�����*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct qnode
{
	int* data;
	int front, rear;
	int MAXSIZE;
}queue;

queue init_queue(queue*, int); //��ʼ��
bool is_full(queue*); //����
bool is_empty(queue*);//�п�
void enQueue(queue*, int); //�����м�Ԫ��
void deQueue(queue*, int); //�����м�����

int main(void)
{
	queue Q;
	init_queue(&Q, 12);
	enQueue(&Q, 1);
	return 0;
}

queue init_queue(queue* q, int MAX)
{
	q = (queue*)malloc(sizeof(queue));
	q->data = (int*)malloc(sizeof(int) * MAX);
	q->front = 0;
	q->rear = 0;
	q->MAXSIZE = MAX;

	return *q;
}
//����
bool is_full(queue* q)
{
	if (q->rear +1== q->MAXSIZE)
		return true;
	else
		return false;
}
//�п�
bool is_empty(queue* q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}
//������
void enQueue(queue* q, int e)
{
	if (is_full(q))
		printf("�������޷�д��Ԫ�أ�\n");
	else
	{
		q->rear++;
		(q->data)[q->rear] = e;
		printf("��ӳɹ������Ԫ��Ϊ%d ,�ڵ�%d��λ��", e, q->rear + 1);
	}
}
//����
void deQueue(queue* q, int x)
{
	if (is_empty(q))
		printf("�ӿգ�����ʧ�ܣ�\n");
	else
	{
		
		printf("����Ԫ��Ϊ��");
		for (int i = q->front; i < q->front + x; ++i)
			printf("% d", q->data[i]);
		q->front = q->front + x;

	}
}
/*
	���δ���д��2020/1/1����δ��ʽ��Ϊ�������ҵ��һԱ��ʱ��д�ģ������д���
		
		��1��������δ��������쳣:д�����Ȩ�޳�ͻ��
		q->data �� 0x1110112��

		��2������	C6011	ȡ���� NULL ָ�롰q�������á�		��32��

*/
