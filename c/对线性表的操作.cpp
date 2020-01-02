#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Arr
{
	int* a; //存储第一个元素的地址
	int length; //线性表所能容纳的最大长度
	int cnt;//有效长度
};
/*-------各个功能函数---------------------*/
void init_arr(struct Arr*, int); //初始化
bool is_empty(struct Arr*);//判断表是否为空
bool is_full(struct Arr*); //判断表是否满了？
void show_arr(struct Arr*); //输出表
bool insert_arr(struct Arr*, int, int);//在线性表中插入元素
bool delete_arr(struct Arr*, int); //删除某个元素
void inversion_arr(struct Arr*); //倒序
void sort_arr(struct Arr*); //冒泡排序
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
//初始化函数
void init_arr(struct Arr* arr, int length)
{
	arr->a = (int*)malloc(sizeof(int) * length);
	if (NULL == arr->a)
	{
		printf("内存分配失败!\n");
		exit(-1); // 终止整个程序
	}
	else
	{
		arr->length = length;
		arr->cnt = 0;
	}
}

//判断表是否为空？
bool is_empty(struct Arr* arr)
{
	if (0 == arr->cnt)
		return true;
	else
		return false;
}
//判断表是否满了？
bool is_full(struct Arr* arr)
{
	if (arr->cnt == arr->length)
		return true;
	else
		return false;
}
//输出表
void show_arr(struct Arr * arr)
{
	if (is_empty(arr))
		printf("线性表为空!\n");
	else
		for (int i = 0; i < arr->cnt; i++)
			printf("% d", arr->a[i]);
			printf("/n");
}
/*
	1.在线性表中插入某个元素
	2.也可以采用do....while循环进行不断添加元素
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
//删除线性表中的某个元素
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
//倒序
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
//冒泡排序
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