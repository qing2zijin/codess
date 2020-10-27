#include<iostream>
int count;
extern void write_extern();

int main(int argc, char*argv[])
{
	count = 5;
	write_extern();

	return 0;
}
