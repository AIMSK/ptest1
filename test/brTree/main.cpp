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
    brNodeFunc brt;
    brTreeNode * head;
    brTreeNode * tmp;
    head -> init_head(1, &head);
    for(int i = 2; i < 40; i++)
    {
        head -> insert_node(new brTreeNode(i), &head);
    }

    head -> print_tree(head);
    //tmp = head -> find_node(100, head);
    //if(tmp == NULL) {printf("no \n");}
    //delete tmp;
    //test1();
    return 0;
}

void test1()
{
    linklistNode<int> fifo(0);
    int tmp;
    fifo.push_back(6);
    fifo.push_back(5);
    fifo.push_back(4);
    fifo.push_back(5);
    fifo.push_back(1);
    printf("size of fifo %d\n",fifo.size());
    while(fifo.pop_front(&tmp)){ printf("pop %d\n", tmp); }
}
