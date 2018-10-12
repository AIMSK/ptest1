#include <stdio.h>
#include <stdlib.h>
#include "brTreeFunc.h"
int main(int argc, char ** argv)
{
    //brNode * tmp;
    //tmp = (brNode *) malloc(sizeof(brNode));
#ifdef DEBUG
    printf("main test \n");
#endif
    brNodeFunc brt;
    brNodeFunc *pbrt = new brNodeFunc();
    delete pbrt;
    return 0;
}
