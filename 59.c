//动态内存管理

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    //向内存申请10个整形的空间
    int* p = malloc(10*sizeof(int));
    //int* p1 = calloc(10,sizeof(int));    //开辟空间，空间的每个字节初始化为0，不是随机值
    if(p==NULL)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        int i = 0;
        for (i=0 ; i<10 ; i++)
        {
            *(p+i) = i ;
        }
        for (i=0 ; i<10 ; i++)
        {
            printf("%d\n",*(p+i));
        }
    }
    free(p);
    p=NULL; 
    return 0;
}