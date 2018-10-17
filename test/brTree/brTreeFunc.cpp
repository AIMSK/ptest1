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
brTreeNode :: brTreeNode( int key )
{
    this->parent = NULL;
    this->right = NULL;
    this->left = NULL;
    this->color = color;
    this->key = key;
}

int brTreeNode :: insert_node(brTreeNode * node, brTreeNode ** head)
{
//#ifdef DEBUG
//    printf("br tree insert\n");
//#endif
    brTreeNode * tmp;
    if(*head == NULL) { *head = node; node->parent = NULL; node->color = BLACK; return 0; };
    tmp = *head; 
    node -> color = RED;
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
    brTreeNode * tmp;
    //printf("--insert--%d-%d-%d-\n", node->key, node->parent->color, node->parent->key);
    if ( node -> parent == NULL ){ return 0 ; }
    if ( node -> parent -> color == BLACK ){ 
        //printf("-pb-%d-%d-\n", node->key, node->color); 
        return 0 ; }
    else
    {
        tmp = node; 
        do
        {    
            //printf("--%d--\n", tmp->key);
            tmp = balance_one( tmp, head );
            print_tree(*head);
            //printf("--%d--%d--\n", tmp->key, tmp->color);
        } 
        while ( tmp == NULL );
    }
    return 0;
}

brTreeNode * brTreeNode :: balance_one(brTreeNode * node, brTreeNode ** head )
{
    brTreeNode * uncle;
    //if ( node -> parent == NULL ) { node -> color =  BLACK; * head = node; return NULL; }
    if ( node -> parent -> color == BLACK ) { return NULL; }
    else 
    {
        uncle  = node -> get_uncle( node );
        if ( uncle -> color == RED ){ node -> parent -> color = BLACK; uncle -> color = BLACK; return node -> parent -> parent; }
        else 
        {
            if ( is_left( node -> parent ) == true )
            {
                if( is_left( node ) == false ) { node -> left_rotate( node -> parent, head ); } //bang zhi
                node -> color = BLACK; 
                node -> parent -> color = RED;
                node -> right_rotate( node -> parent , head );
                return NULL;
            }
            else 
            {
                if( is_left( node ) == true ) { node -> right_rotate( node -> parent, head ); } //bang zhi
                node -> color = BLACK; 
                node -> parent -> color = RED;
                node -> left_rotate( node -> parent , head );
                return NULL;
            }
            
        }
    }
    return 0;
}

brTreeNode * brTreeNode :: get_uncle ( brTreeNode * node )
{
    if( node -> parent == NULL || node -> parent -> parent == NULL || node == NULL ){ return NULL; }
    if( node -> parent  == node -> parent -> parent -> left ){ return node -> parent -> parent -> right; }
    else { return node -> parent -> parent -> left; }
}

bool brTreeNode :: is_left ( brTreeNode * node ) //optm
{
    if( node -> parent == NULL ) { return true; }
    if( node -> parent -> left == node ) { return true; }
    else { return false; } 
}



int brTreeNode :: delete_node(int key, brTreeNode ** head)
{
//#ifdef DEBUG
//    printf("br tree insert\n");
//#endif
    brTreeNode * tmp;
    return 0;
}


int brTreeNode :: left_rotate(brTreeNode * node, brTreeNode ** head)
{
    brTreeNode * tmp;
    if( node->right == NULL ) { printf("left rotate fail"); return 1; }
    tmp = node->right;
    node->right = tmp->left;
    if( node->right != NULL ){ node->right->parent = node; }
    tmp->parent = node->parent;
    if( node->parent == NULL ) { tmp -> color = BLACK; *head = tmp; }
    else if( node == node->parent->left ){ node->parent->left = tmp; }
    else { node->parent->right = tmp; }
    tmp->left = node;
    node->parent = tmp;
    return 0;
}
int brTreeNode :: right_rotate (brTreeNode * node, brTreeNode ** head)
{
    brTreeNode * tmp;
    if( node->left == NULL ) { printf("right rotate fail"); return 1; }
    tmp = node->left;
    node->left = tmp->right;
    if( node->left != NULL ){ node->left->parent = node; }
    tmp->parent = node->parent;
    if( node->parent == NULL ) { tmp -> color = BLACK; *head = tmp; }
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
    printf("------------------------\n");
    if( head == NULL){ printf("null\n"); return 0; }
    fifo.push_back(head);
    fifo.push_back(NULL);
    while(fifo.pop_front(&tmp))
    {
        if( tmp == NULL ) { if(n ==1) { return 0; }else { fifo.push_back(NULL); printf("\n"); n ++; }}
        else 
        {
            n = 0;
            if(tmp->parent != NULL){ printf(" %d(%d)%d ", tmp->key, tmp->parent->key, tmp -> color); }
            else { printf(" %d(null)%d ", tmp->key, tmp->color); }
            if( tmp->left != NULL ){ fifo.push_back(tmp->left); }
            if( tmp->right != NULL){ fifo.push_back(tmp->right); }
        } 
    }

    return 0; 
}

