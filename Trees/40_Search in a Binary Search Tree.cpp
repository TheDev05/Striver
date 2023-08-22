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
        this->left = this->right;
    }
};

TreeNode *traverse(TreeNode *root, int target)
{
    if (root == NULL)
        return NULL;

    if (target == root->val)
        return root;

    TreeNode *val1 = NULL, *val2 = NULL;
    if (target < root->val)
        val1 = traverse(root->left, target);
    else
        val2 = traverse(root->right, target);

    if (val1)
        return val1;

    return val2;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int target;
    std::cin >> target;

    TreeNode *result = NULL;
    result = traverse(root, target);
}