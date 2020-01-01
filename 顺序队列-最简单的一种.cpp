
/*最简单的一种顺序队列*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct qnode
{
	int* data;
	int front, rear;
	int MAXSIZE;
}queue;

queue init_queue(queue*, int); //初始化
bool is_full(queue*); //判满
bool is_empty(queue*);//判空
void enQueue(queue*, int); //进队列及元素
void deQueue(queue*, int); //出队列及个数

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
//判满
bool is_full(queue* q)
{
	if (q->rear +1== q->MAXSIZE)
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
void enQueue(queue* q, int e)
{
	if (is_full(q))
		printf("队满，无法写进元素！\n");
	else
	{
		q->rear++;
		(q->data)[q->rear] = e;
		printf("入队成功，入队元素为%d ,在第%d个位置", e, q->rear + 1);
	}
}
//出队
void deQueue(queue* q, int x)
{
	if (is_empty(q))
		printf("队空，出队失败！\n");
	else
	{
		
		printf("出队元素为：");
		for (int i = q->front; i < q->front + x; ++i)
			printf("% d", q->data[i]);
		q->front = q->front + x;

	}
}
/*
	本段代码写于2020/1/1，在未正式成为计算机行业的一员的时候写的，其中有错误：
		
		（1）引发了未经处理的异常:写入访问权限冲突。
		q->data 是 0x1110112。

		（2）警告	C6011	取消对 NULL 指针“q”的引用。		第32行

*/
