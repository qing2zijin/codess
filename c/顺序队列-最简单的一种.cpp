
/*最简单的一种顺序队列*/

#include<stdio.h>

#define MAXSIZE 12

typedef struct qnode
{
	//int MAXSIZE;
	int data[MAXSIZE];
	int front, rear;
}queue;

queue init_queue(queue*); //初始化
bool is_full(queue*); //判满
bool is_empty(queue*);//判空
queue enQueue(queue*, int); //进队列及元素
queue deQueue(queue*, int); //出队列及个数

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
//判满
bool is_full(queue* q)
{
	if (q->rear + 1 == MAXSIZE)
		return true;
	else
		return false;
}
//判空
bool is_empty(queue* q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}
//进队列
queue enQueue(queue* q, int e)
{
	if (is_full(q))
		printf("队满，无法写进元素！\n");
	else
	{
		
		(q->data)[q->rear] = e;
		printf("入队成功，入队元素为%d ,在第%d个位置\n", e, q->rear + 1);
		q->rear++;
		return *q;
	}
}
//出队
queue deQueue(queue* q, int x)
{
	if (is_empty(q))
		printf("队空，出队失败！\n");
	else
	{

		printf("出队元素为：");
		for (int i = q->front; i < q->front + x; ++i)
			printf("%d,", (q->data)[i]);
		//printf("出队成功！\n");
		q->front = q->front + x;
		return *q;
	}
}
/*
入队成功，入队元素为1 ,在第2个位置
入队成功，入队元素为3 ,在第3个位置
入队成功，入队元素为6 ,在第4个位置
入队成功，入队元素为7 ,在第5个位置
出队元素为：-858993460,1,
*/

/*不知道为啥出队中，第一个值为垃圾值？现在能力有限，2020/1/2 */
