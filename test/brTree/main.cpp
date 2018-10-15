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
    brTreeNode * tmp2;
    brTreeNode * tmp = new brTreeNode(BLACK, 5);
    head = tmp;
    tmp = new brTreeNode(BLACK, 10);
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 2);
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 4);
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 12);
    tmp2 = tmp;
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 19);
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 1);
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 6);
    tmp->insert_node(tmp, &head);
    tmp = new brTreeNode(BLACK, 11);
    tmp->insert_node(tmp, &head);

    tmp->print_tree(head);
    //tmp->left_rotate(tmp2, &head);
    tmp->right_rotate(tmp2, &head);

    tmp->print_tree(head);
    delete tmp;
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
