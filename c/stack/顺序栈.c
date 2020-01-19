/*
	顺序存储结构的栈
*/
#include<stdio.h>

#define MAXSIZE 10
typedef struct
{
	int data[MAXSIZE];  //数组data 长度为10
	int top;
}sqStack;

sqStack init(sqStack*);       //初始化
sqStack push(sqStack*);       //进栈
sqStack pop(sqStack*);        //出栈

int main(void)
{
	sqStack S;

	init(&S);
	push(&S);
	pop(&S);

	return 0;
}

//初始化
sqStack init(sqStack* S)
{
	S->top = 0;
	return *S;
}

//进栈
sqStack push(sqStack * S)
{
	if (S->top == MAXSIZE - 1)
		printf("栈满，进栈失败！\n");
	int e;
	printf("请输入您需要进栈的元素：");
	scanf_s("%d", &e);
	S->top++;
	S->data[S->top] = e;
	
	return *S;
}

//出栈
sqStack pop(sqStack * S)
{
	if (S->top == -1)
		printf("栈空，无法出栈！\n");

	printf("出栈元素为：%d", (S->data)[S->top] );
	S->top--;

	return *S;
}

/* 
请输入您需要进栈的元素：56666
出栈元素为：56666
---------------------------------
通过VS2019编写，2020/1/6
---------------------------------
*/