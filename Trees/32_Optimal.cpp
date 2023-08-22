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

int left(TreeNode *root)
{
    int left = 0;
    while (root)
    {
        left++;
        root = root->left;
    }

    return left;
}

int right(TreeNode *root)
{
    int right = 0;
    while (root)
    {
        right++;
        root = root->right;
    }

    return right;
}

int traverse(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = left(root), rightHeight = right(root);
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;
    else
        return 1 + traverse(root->left) + traverse(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << traverse(root);
}