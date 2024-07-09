#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BinarySearchTree {
private:
    TreeNode* root;

public:
    BinarySearchTree();

    BinarySearchTree(const BinarySearchTree& rhs);

    BinarySearchTree& operator=(const BinarySearchTree& rhs);

    ~BinarySearchTree();

    void clear();

    TreeNode* search(int val);

    void insert(int val);

    void remove(int val);

    TreeNode* minNode();
};

#endif