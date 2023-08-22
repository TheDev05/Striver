#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int temp)
    {
        this->val = temp;
        this->left = this->right = NULL;
    }
};

void traverse(TreeNode *root, std::vector<int> &inorder)
{
    if (root == NULL)
        return;

    traverse(root->left, inorder);
    inorder.push_back(root->val);
    traverse(root->right, inorder);

    return;
}

class BSTIterator
{
public:
    int index = -1;
    std::vector<int> inorder;

    BSTIterator(TreeNode *root)
    {
        traverse(root, inorder);
    }

    int next()
    {
        index++;
        return inorder[index];
    }

    bool hasNext()
    {
        return (index == inorder.size() - 1) ? false : true;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    BSTIterator obj(root);
}