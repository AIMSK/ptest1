#include <stdio.h>

int main (int argc, char ** argv)
{
    wchar_t * chstr = L"测试";
    unsigned int * p =  (unsigned int *) chstr;
    printf ("0x%x\n",p[0]);
    return 0;
}
