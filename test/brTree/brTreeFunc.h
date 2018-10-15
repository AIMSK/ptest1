#define RED   0
#define BLACK 1

class brTreeNode;

typedef struct brNode_
{
    brNode_ * parent;
    brNode_ * right;
    brNode_ * left;
    bool color;
    int key;
}brNode;

typedef struct llNode_
{
    brTreeNode * elem;
    llNode_ * next;
}llNode;

class brNodeFunc
{
    public:

    int insert_node(brNode * node);
};

class brTreeNode
{
    public:

    brTreeNode * parent;
    brTreeNode * right;
    brTreeNode * left;
    bool color;
    int key;

    public:

    //brTreeNode(){};
    brTreeNode();
    brTreeNode( int key );
    int insert_node (brTreeNode * node, brTreeNode ** head);
    int delete_node(int key, brTreeNode ** head);
    int right_rotate(brTreeNode * node, brTreeNode ** head);
    int left_rotate (brTreeNode * node, brTreeNode ** head);
    int rebalance(brTreeNode * node, brTreeNode ** head);
    int print_tree(brTreeNode * head);
        
};

template <class Type_S> 
class linklistNode
{
    
    public: 

    Type_S elem;
    linklistNode * next;
    static Type_S err_value;

    public:

    //linklistNode();
    linklistNode(Type_S elem);
    int push_back( Type_S elem );
    bool pop_front( Type_S * pe );
    int size();

};

template <class Type_S>
Type_S linklistNode<Type_S> :: err_value;

//template <class Type_S> 
//linklistNode<Type_S> :: linklistNode()
//{
//    //this->elem = NULL;
//    this-> next = NULL;
//}

template <class Type_S> 
linklistNode<Type_S> :: linklistNode(Type_S elem)
{
    this->elem = elem;
    this-> next = NULL;
}

template <class Type_S> 
int linklistNode<Type_S> :: push_back( Type_S elem )
{
    linklistNode<Type_S> * tmp = this; 
    linklistNode<Type_S> * tar = new linklistNode( elem );
    while (tmp->next != NULL){ tmp = tmp -> next; }
    tmp->next = tar;
    return 0;
}

template <class Type_S> 
bool linklistNode<Type_S> :: pop_front( Type_S * pe )
{
    linklistNode<Type_S> * head = this; 
    Type_S elem;
    if( head -> next == NULL ) { return false; }
    else 
    { 
        linklistNode<Type_S> * tmp;
        tmp = head -> next;
        elem = tmp -> elem;
        head -> next = head -> next -> next;
        delete tmp;
        *pe = elem;
        return true;
    }
}

template <class Type_S> 
int linklistNode<Type_S> :: size()
{
    linklistNode<Type_S> * tmp;
    tmp = this;
    int num = 0;
    while( tmp -> next != NULL ){ tmp = tmp -> next; num = num + 1; }
    return num;
}
