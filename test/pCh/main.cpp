#include <stdio.h>
#include <string.h>

int main (int argc, char ** argv)
{
    wchar_t * chstr = L"测试";
    char chr;
    unsigned int * p =  (unsigned int *) chstr;
    //printf ("0x%x\n",p[0]);
    FILE * fr; 
    fr = fopen("piny.dat","rb");
    if(fr == NULL)
    {
        printf("open error\n");
        return 0;
    }
    //fseek( fr, 3, 0);
    //fread( &chr, 1, 1, fr);
    //printf("%c \n", chr);

    fseek( fr, 3, 0);
    fread( &chr, 1, 1, fr);
    printf("%c \n", chr);

    fseek( fr, 0x100, 0);
    fread( &chr, 1, 1, fr);
    printf("%c \n", chr);

    fseek( fr, 0x51a4, 0);
    fread( &chr, 1, 1, fr);
    printf("%c \n", chr);

    fseek( fr, 0x51a5, 0);
    fread( &chr, 1, 1, fr);
    printf("%c \n", chr);
    return 0;
}
