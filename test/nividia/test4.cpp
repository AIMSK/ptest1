#include <stdio.h>
#include <stdlib.h>

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
struct BinaryTree {
    int weight;
    struct BinaryTree *left, *right;
};
// ----------------------------

int subtree_count(const struct BinaryTree* root, int m)
{
    // Complete your code here
    if (root->weight == m)
        return 1;
    else
        return 0;
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#ifndef __NVIDIA_TEST_
// ----------------------------

int main()
{
    struct BinaryTree* root;
    int i;

    // Small test case
    root = (struct BinaryTree*) malloc(sizeof(struct BinaryTree));
    root->weight = 10;
    root->left = root->right = 0;
    printf("Test 1: subtree_count(root, 100) = %d\n", subtree_count(root, 100));
    free(root);

    // Large test case
    root = (struct BinaryTree*) malloc(100000 * sizeof(struct BinaryTree));
    for (i = 0; i < 100000; i++) {
        root[i].weight = 1;
        root[i].left = &root[i + 1];
        root[i].right = 0;
    }
    root[0].right = &root[50000];
    root[49999].left = root[99999].left = 0;
    printf("Test 2: subtree_count(root, 100) = %d\n", subtree_count(root, 100));
    free(root);

    // Write your own tests here

    return 0;
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#endif
// ----------------------------
