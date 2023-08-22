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

TreeNode *traverse(TreeNode *root, TreeNode *left, TreeNode *right)
{
    if (root == NULL)
        return NULL;

    if (root->val > left->val && root->val < right->val)
        return root;

    if (root->val == left->val || root->val == right->val)
        return root;

    TreeNode *val1 = NULL, *val2 = NULL;
    val1 = traverse(root->left, left, right);
    val2 = traverse(root->right, left, right);

    if (val1)
        return val1;
    if (val2)
        return val2;

    return NULL;
}

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode *left = root->left, *right = root->right;
    TreeNode *result = traverse(root, left, right);

    if (result)
        std::cout << result->val;
}