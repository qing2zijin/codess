#include<stdio.h>

#define MAXSIZE 20

typedef struct qnode
{
	int data[MAXSIZE];
	int front;
	int rear;
}queue;

queue init_Queue(queue*); //初始化
int is_full(queue*); //判满
int is_empty(queue*); //判空
queue enQueue(queue*, int);//进队
queue deQueue(queue*, int);//出队及个数

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
//初始化
queue init_Queue(queue* q)
{
	q->front = 0;
	q->rear = 0;
	return *q;
}
//判满
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
//判空
int is_empty(queue* q)
{
	return(q->front == q->rear);
}
//进队列
queue enQueue(queue* q, int e)
{
	if (is_full(q))
		printf("进队失败！\n");
	else
	{
		q->data[q->rear] = e;
		q->rear = (q->rear + 1) % MAXSIZE;
		printf("进队成功！\n");
	}
	return *q;
}
//出队
queue deQueue(queue* q, int x)
{
	if (is_empty(q))
		printf("出队失败！\n");
	else
	{
		for (int i = q->front; i < q->front + x; ++i)
			printf("出队元素为%d, 第%d个位置\n", q->data[i], i+1);
		q->front = (q->front + 1) % MAXSIZE;
	}
	return *q;
}

/*
进队成功！
进队成功！
进队成功！
进队成功！
出队元素为23, 第1个位置
出队元素为2, 第2个位置
出队元素为3, 第3个位置
--------------------------
通过vs2019编写，2020/1/3
--------------------------
*/