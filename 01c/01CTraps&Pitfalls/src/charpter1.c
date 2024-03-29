//========================================================================
//词法陷阱
//========================================================================
#include<stdio.h>
#include"charpter.h"
//test a---b and a - -- b
int charpter1_test()
{
	/*解析1：
	C语言编译器对于代码的分解采用的是贪心算法;
	按照贪心算法分解a+++++b为：((a++)++)+b
	因为a++的结果为左值，而左值不能再进行运算，故a+++++b编译不能通过
	除非写成a+++ ++b，在++b前面有个空格，这时候根据贪心算法分解为：
	(a++)+(++b)*/
	/*解析2：
	“a+++++b”这一段根本就无法解析，编译系统从左至右扫描整条语句，
	先遇到a++，判断出来是一个a的后缀自加运算，然后接着扫描，遇到一个+，+是一个二目运算符，
	它的左边已经有一个运算数a++了，系统就向右搜索第二个运算数，
	又遇到一个+，++比+的运算级别要高，这时，编译系统就将两个+看成一个整体来处理，
	既然是++，编译系统就认定，肯定它的左边或右边有一个变量，编译系统先搜索左边，
	发现++，不是变量，再搜索右边，发现+b，+b是什么东西？编译系统是无法搞明白的*/
	int a =1;
	int b =1;
	int c =0;
	//c = a+++++b;//错误的
	c=(a++)+(++b);
	printf("a= %d\n",c);
	/*
	int a = 4;
	int b = 5;
	int c = a---b;
	int d = 0;
	a = 4;
	b = 5;
	d = a - -- b;
	printf("c = %d,d = %d\n",c,d);*/
	return 0;
}