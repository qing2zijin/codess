#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Arr
{
	int* a; //�洢��һ��Ԫ�صĵ�ַ
	int length; //���Ա��������ɵ���󳤶�
	int cnt;//��Ч����
};
/*-------�������ܺ���---------------------*/
void init_arr(struct Arr*, int); //��ʼ��
bool is_empty(struct Arr*);//�жϱ��Ƿ�Ϊ��
bool is_full(struct Arr*); //�жϱ��Ƿ����ˣ�
void show_arr(struct Arr*); //�����
bool insert_arr(struct Arr*, int, int);//�����Ա��в���Ԫ��
bool delete_arr(struct Arr*, int); //ɾ��ĳ��Ԫ��
void inversion_arr(struct Arr*); //����
void sort_arr(struct Arr*); //ð������
/*-----------------------------------------*/
int main(void)
{
	struct Arr arr;
	//int val;

	init_arr(&arr, 6);
	insert_arr(&arr, 1, 2);
	insert_arr(&arr, 2, 3);
	insert_arr(&arr, 5, 6);
	insert_arr(&arr, 3, 3);
	insert_arr(&arr, 4, 2);
	insert_arr(&arr, 6, 18);
	show_arr(&arr);
}
/*---------------------------------------------*/
//��ʼ������
void init_arr(struct Arr* arr, int length)
{
	arr->a = (int*)malloc(sizeof(int) * length);
	if (NULL == arr->a)
	{
		printf("�ڴ����ʧ��!\n");
		exit(-1); // ��ֹ��������
	}
	else
	{
		arr->length = length;
		arr->cnt = 0;
	}
}

//�жϱ��Ƿ�Ϊ�գ�
bool is_empty(struct Arr* arr)
{
	if (0 == arr->cnt)
		return true;
	else
		return false;
}
//�жϱ��Ƿ����ˣ�
bool is_full(struct Arr* arr)
{
	if (arr->cnt == arr->length)
		return true;
	else
		return false;
}
//�����
void show_arr(struct Arr * arr)
{
	if (is_empty(arr))
		printf("���Ա�Ϊ��!\n");
	else
		for (int i = 0; i < arr->cnt; i++)
			printf("% d", arr->a[i]);
			printf("/n");
}
/*
	1.�����Ա��в���ĳ��Ԫ��
	2.Ҳ���Բ���do....whileѭ�����в������Ԫ��
 */
bool insert_arr(struct Arr* arr, int x, int val)
{
	if (is_full)
		return false;
	if (x<1 || x>arr->cnt + 1)
		return false;
	for (int i = arr->cnt - 1; i >= x - 1; --i)
		arr->a[i + 1] == arr->a[i];
	arr->a[x] = val;
	arr->cnt++;
	return true;
}
//ɾ�����Ա��е�ĳ��Ԫ��
bool delete_arr(struct Arr* arr, int y)
{
	if (is_full(arr))
		return false;
	if (y<1 || y>arr->cnt + 1)
		return false;
	for (int i = y; i <= arr->cnt - 1; ++i)
		arr->a[i-1] = arr->a[i];
	arr->cnt--;
	return true;
}
//����
void inversion_arr(struct Arr* arr)
{
	int i = 0, j = arr->cnt - 1, t;

	while (i<j)
	{
		t = arr->a[i];
		arr->a[i] = arr->a[j];
		arr->a[j] = t;
		++i;
		--j;
	}
	return;
}
//ð������
void sort_arr(struct Arr* arr)
{
	int i, j, t;
	
	for (i = 0; i < arr->cnt; ++i)
	{
		for (j = i + 1; j < arr->cnt; ++j)
		{
			if (arr->a[i] > arr->a[j])
			{
				t = arr->a[i];
				arr->a[i] = arr->a[j];
				arr->a[j] = t;
			}
		}
	}
}