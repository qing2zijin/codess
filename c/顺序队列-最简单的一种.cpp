
/*��򵥵�һ��˳�����*/

#include<stdio.h>

#define MAXSIZE 12

typedef struct qnode
{
	//int MAXSIZE;
	int data[MAXSIZE];
	int front, rear;
}queue;

queue init_queue(queue*); //��ʼ��
bool is_full(queue*); //����
bool is_empty(queue*);//�п�
queue enQueue(queue*, int); //�����м�Ԫ��
queue deQueue(queue*, int); //�����м�����

int main(void)
{
	queue Q;
	init_queue(&Q);
	enQueue(&Q, 1);
	enQueue(&Q, 3);
	enQueue(&Q, 6);
	enQueue(&Q, 7);
	deQueue(&Q, 2);

	return 0;
}

queue init_queue(queue* q)
{
	//q = (queue*)malloc(sizeof(queue));
	q->front = 0;
	q->rear = 0;

	return *q;
}
//����
bool is_full(queue* q)
{
	if (q->rear + 1 == MAXSIZE)
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
queue enQueue(queue* q, int e)
{
	if (is_full(q))
		printf("�������޷�д��Ԫ�أ�\n");
	else
	{
		
		(q->data)[q->rear] = e;
		printf("��ӳɹ������Ԫ��Ϊ%d ,�ڵ�%d��λ��\n", e, q->rear + 1);
		q->rear++;
		return *q;
	}
}
//����
queue deQueue(queue* q, int x)
{
	if (is_empty(q))
		printf("�ӿգ�����ʧ�ܣ�\n");
	else
	{

		printf("����Ԫ��Ϊ��");
		for (int i = q->front; i < q->front + x; ++i)
			printf("%d,", (q->data)[i]);
		//printf("���ӳɹ���\n");
		q->front = q->front + x;
		return *q;
	}
}
/*
��ӳɹ������Ԫ��Ϊ1 ,�ڵ�2��λ��
��ӳɹ������Ԫ��Ϊ3 ,�ڵ�3��λ��
��ӳɹ������Ԫ��Ϊ6 ,�ڵ�4��λ��
��ӳɹ������Ԫ��Ϊ7 ,�ڵ�5��λ��
����Ԫ��Ϊ��-858993460,1,
*/

/*��֪��Ϊɶ�����У���һ��ֵΪ����ֵ�������������ޣ�2020/1/2 */
