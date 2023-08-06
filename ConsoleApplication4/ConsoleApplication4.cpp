// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "stdio.h"
typedef struct {
   // char a;
   // char b;
   // int c;
    double d;
} T1,*pT1;

typedef struct {

    char a;

    char b;

    char c;

   // int d;
    T1 e;
}T2;
int main()
{
    pT1  b;
    T1   k;
    printf("%d\n",sizeof(T2));
}
