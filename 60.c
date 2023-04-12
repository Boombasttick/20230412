//动态内存管理

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    //向内存申请10个整形的空间
    int* p = malloc(20);
    if(p==NULL)
    {
        printf("%s\n",strerror(errno));
    }
    else
    {
        int i = 0;
        for (i=0 ; i<5 ; i++)
        {
            *(p+i) = i ;
        }
    }
    int* p2 = realloc(p,40);
    int i = 0;
    for (i=0 ; i<10 ; i++)
    {
        printf("%d\n",*(p2+i));
    }
    free(p2);
    p=NULL; 
    return 0;
}