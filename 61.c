//动态内存管理--易错（只释放一部分）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int* p = realloc(NULL,40);//等同malloc(40)
    if (p == NULL)
    {
        return  0;  
    }
    int i=0;
    for (i=0 ; i<10 ; i++)
    {
        *p++ = i;  //后置++，先使用后加1
    }
    //free(p);    错误，p值已经变化，此时已经非法越界，不可以只释放一部分
    //p=NULL;  
    free(p-10);
    return 0;
}

