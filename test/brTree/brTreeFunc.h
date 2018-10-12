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
    brTreeNode(bool color, int key);
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

    public:

    linklistNode(Type_S elem);
};
