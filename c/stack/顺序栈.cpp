/*
	˳��洢�ṹ��ջ
*/
#include<stdio.h>

#define MAXSIZE 10
typedef struct
{
	int data[MAXSIZE];  //����data ����Ϊ10
	int top;
}sqStack;

sqStack init(sqStack*);       //��ʼ��
sqStack push(sqStack*);       //��ջ
sqStack pop(sqStack*);        //��ջ

int main(void)
{
	sqStack S;

	init(&S);
	push(&S);
	pop(&S);

	return 0;
}

//��ʼ��
sqStack init(sqStack* S)
{
	S->top = 0;
	return *S;
}

//��ջ
sqStack push(sqStack * S)
{
	if (S->top == MAXSIZE - 1)
		printf("ջ������ջʧ�ܣ�\n");
	int e;
	printf("����������Ҫ��ջ��Ԫ�أ�");
	scanf_s("%d", &e);
	S->top++;
	S->data[S->top] = e;
	
	return *S;
}

//��ջ
sqStack pop(sqStack * S)
{
	if (S->top == -1)
		printf("ջ�գ��޷���ջ��\n");

	printf("��ջԪ��Ϊ��%d", (S->data)[S->top] );
	S->top--;

	return *S;
}

/* 
����������Ҫ��ջ��Ԫ�أ�56666
��ջԪ��Ϊ��56666
---------------------------------
ͨ��VS2019��д��2020/1/6
---------------------------------
*/