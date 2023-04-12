//动态内存管理--易错（对同一块动态内存多次释放）

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void getmemory(char* p)
{
    p = (char*)malloc(100);
}

void test(void)
{
    char* str = NULL;
    getmemory(str);
    strcpy(str,"hello wrold");
    printf(str); 
    free{str};
    str = NULL;
}

int main()
{
    test();
    return 0;
}

//运行代码程序会崩溃
//程序存在内存泄露的问题
//str以值传递的形式给p
//p是getmemory函数的形参，只能函数内部有效
//等getmemory函数返回之后，动态开辟内存尚未释放并且无法找到，所以会造成内存泄漏


//改正1：
void getmemory(char** p)
{
    *p = (char*)malloc(100);
}

void test(void)
{
    char* str = NULL;
    getmemory(&str);
    strcpy(str,"hello wrold");
    printf(str); 
    free{str};
    str = NULL;
}

//改正2：
char* getmemory(char* p)
{
    p = (char*)malloc(100);
    return p;
}

void test(void)
{
    char* str = NULL;
    str = getmemory(str);
    strcpy(str,"hello wrold");
    printf(str); 
    free{str};
    str = NULL;
}