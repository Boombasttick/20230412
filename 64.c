////动态内存管理

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void getmemory(char** p,int num)
{
    *p = (char*)malloc(num);
}

void test(void)
{
    char* str = NULL;
    getmemory(&str,100);
    strcpy(str,"hello wrold");
    printf(str); 
    free(str);
    str = NULL;
}

int main()
{
    test();
    return 0;
}