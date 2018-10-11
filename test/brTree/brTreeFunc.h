typedef struct brNode_
{
    brNode_ * parent;
    brNode_ * right;
    brNode_ * left;
    int key;
}brNode;

class brNodeFunc
{
public:
    int insert_node(brNode * node);
};


