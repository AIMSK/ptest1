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
// class brTreeNode

brTreeNode :: brTreeNode(){}
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
    return 0;
}

int brTreeNode :: delete_node(int key, brTreeNode ** head)
{
#ifdef DEBUG
    printf("br tree insert\n");
#endif
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
