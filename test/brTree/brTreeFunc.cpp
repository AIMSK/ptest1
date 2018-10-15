#include <stdio.h>
#include "brTreeFunc.h"

int brNodeFunc :: insert_node(brNode * node)
{
#ifdef DEBUG
    printf("br tree insert\n");
#endif
    return 0;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
// class brTreeNode

brTreeNode :: brTreeNode()
{
    this->parent = NULL;
    this->right = NULL;
    this->left = NULL;
    this->color = 0;
    this->key = 0;
}
brTreeNode :: brTreeNode(bool color, int key)
{
    this->parent = NULL;
    this->right = NULL;
    this->left = NULL;
    this->color = color;
    this->key = key;
}

int brTreeNode :: insert_node(brTreeNode * node, brTreeNode ** head)
{
#ifdef DEBUG
    printf("br tree insert\n");
#endif
    brTreeNode * tmp;
    if(*head == NULL) { *head = node; node->parent = NULL; return 0; };
    tmp = *head; 
    while(1)
    {
        if( node->key > tmp->key )
        {
            if( tmp->right == NULL ) { tmp->right = node; node->parent = tmp; rebalance(node, head); return 0; }
            else { tmp = tmp->right; }
        }
        else if ( node->key < tmp->key )
        {
            if( tmp->left == NULL ) { tmp->left = node; node->parent = tmp; rebalance(node, head); return 0; }
            else { tmp = tmp->left; }
        }
        else if( node->key == tmp->key ){ return 1; }
    }
    return 0;
}

int brTreeNode :: rebalance(brTreeNode * node, brTreeNode ** head)
{
    return 0;
}


int brTreeNode :: delete_node(int key, brTreeNode ** head)
{
#ifdef DEBUG
    printf("br tree insert\n");
#endif
    brTreeNode * tmp;
    return 0;
}


int brTreeNode :: left_rotate(brTreeNode * node, brTreeNode ** head)
{
    brTreeNode * tmp;
    tmp = node->right;
    node->right = tmp->left;
    if(node->right != NULL){ node->right->parent = node; }
    tmp->parent = node->parent;
    if(node->parent == NULL) { *head = tmp; }
    else if( node == node->parent->left ){ node->parent->left = tmp; }
    else { node->parent->right = tmp; }
    tmp->left = node;
    node->parent = tmp;
    return 0;
}
int brTreeNode :: right_rotate (brTreeNode * node, brTreeNode ** head)
{
    brTreeNode * tmp;
    tmp = node->left;
    node->left = tmp->right;
    if(node->left != NULL){ node->left->parent = node; }
    tmp->parent = node->parent;
    if(node->parent == NULL) { *head = tmp; }
    else if( node == node->parent->left ){ node->parent->left = tmp; }
    else { node->parent->right = tmp; }
    tmp->right = node;
    node->parent = tmp;
    return 0;
}



int brTreeNode :: print_tree(brTreeNode * head)
{
    linklistNode<brTreeNode *> fifo(NULL); 
    brTreeNode * tmp;
    int n = 0;
    if( head == NULL){ printf("null\n"); return 0; }
    fifo.push_back(head);
    fifo.push_back(NULL);
    while(fifo.pop_front(&tmp))
    {
        if( tmp == NULL ) { if(n ==1) { return 0; }else { fifo.push_back(NULL); printf("\n"); n ++; }}
        else 
        {
            n = 0;
            if(tmp->parent != NULL){ printf(" %d(%d) ", tmp->key, tmp->parent->key); }
            else { printf(" %d(null) ", tmp->key); }
            if( tmp->left != NULL ){ fifo.push_back(tmp->left); }
            if( tmp->right != NULL){ fifo.push_back(tmp->right); }
        } 
    }

    return 0; 
}

