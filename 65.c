////动态内存管理

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(void)
{
    char* str = (char*)malloc(100);
    strcpy(str,"hello");
    free(str);
    if (str != NULL)
    {
        strcpy(str,"world");
        printf(str); 
    }
}

int main()
{
    test();
    return 0;
}