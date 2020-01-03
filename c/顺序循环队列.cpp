#include<stdio.h>

#define MAXSIZE 20

typedef struct qnode
{
	int data[MAXSIZE];
	int front;
	int rear;
}queue;

queue init_Queue(queue*); //��ʼ��
int is_full(queue*); //����
int is_empty(queue*); //�п�
queue enQueue(queue*, int);//����
queue deQueue(queue*, int);//���Ӽ�����

int main(void)
{
	queue Q;
	init_Queue(&Q);
	enQueue(&Q, 23);
	enQueue(&Q, 2);
	enQueue(&Q, 3);
	enQueue(&Q, 5);
	deQueue(&Q, 3);
	return 0;
}
//��ʼ��
queue init_Queue(queue* q)
{
	q->front = 0;
	q->rear = 0;
	return *q;
}
//����
int is_full(queue* q)
{
	return((q->rear + 1) % MAXSIZE == q->front);
}
	/*
	bool is_full(queue * q)
	{
	  if(q->rear+1 == q->front)
			return true;
	  else
			return false;
	}
	*/
//�п�
int is_empty(queue* q)
{
	return(q->front == q->rear);
}
//������
queue enQueue(queue* q, int e)
{
	if (is_full(q))
		printf("����ʧ�ܣ�\n");
	else
	{
		q->data[q->rear] = e;
		q->rear = (q->rear + 1) % MAXSIZE;
		printf("���ӳɹ���\n");
	}
	return *q;
}
//����
queue deQueue(queue* q, int x)
{
	if (is_empty(q))
		printf("����ʧ�ܣ�\n");
	else
	{
		for (int i = q->front; i < q->front + x; ++i)
			printf("����Ԫ��Ϊ%d, ��%d��λ��\n", q->data[i], i+1);
		q->front = (q->front + 1) % MAXSIZE;
	}
	return *q;
}

/*
���ӳɹ���
���ӳɹ���
���ӳɹ���
���ӳɹ���
����Ԫ��Ϊ23, ��1��λ��
����Ԫ��Ϊ2, ��2��λ��
����Ԫ��Ϊ3, ��3��λ��
--------------------------
ͨ��vs2019��д��2020/1/3
--------------------------
*/