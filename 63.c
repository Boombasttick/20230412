#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* getmemory(void)
{
    char p[]="hello wrold";
    return p;
}

void test(void)
{
    char* str = NULL;
    str = getmemory();
    printf(str); 
}

int main()
{
    test();
    return 0;
}