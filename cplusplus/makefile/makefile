#learn from : https://blog.csdn.net/weixin_38391755/article/details/80380786
	#-c，只编译，不链接成为可执行文件，编译器只是由输入的.c等源代码文件生成.o为后缀的目标文件，通常用于编译不包含主程序的子程序文件。
	
	#-o output_filename，确定输出文件的名称为output_filename，同时这个名称不能和源文件同名。如果不给出这个选项，gcc就给出预设的可执行文件a.out。
#edit: main.o

#	cc -o edit main.o
#main.o: main.c  
#	cc -c main.c
#clean: 
#	rm edit main.o 
#

object_1 = main_extern.o support.o

extern: $(object_1)
	g++ -o extern $(object_1)
main_extern.o: main_extern.cpp  
	g++ -c main_extern.cpp
support.o: support.cpp
	g++ -c support.cpp
clean:
	rm extern $(object_1)


