#include <stdio.h>
#include <stdlib.h>
#include "brTreeFunc.h"
void test1();
int main(int argc, char ** argv)
{
    //brNode * tmp;
    //tmp = (brNode *) malloc(sizeof(brNode));
#ifdef DEBUG
    printf("main debug \n");
#endif
    //brNodeFunc brt;
    brTreeNode * head;
    brTreeNode * tmp = new brTreeNode(BLACK, 1);
    head = tmp;
    tmp = new brTreeNode(BLACK, 10);
    return 0;
}

void test1()
{
}
