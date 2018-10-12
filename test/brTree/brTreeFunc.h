#define RED   0
#define BLACK 1
typedef struct brNode_
{
    brNode_ * parent;
    brNode_ * right;
    brNode_ * left;
    bool color;
    int key;
}brNode;

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

    int insert_node(brTreeNode * node);
    int delete_node(int key);
        
};
