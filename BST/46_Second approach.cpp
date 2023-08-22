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

int traverse(TreeNode *root, long long &min)
{
    if (root == NULL)
        return 0;

    if (traverse(root->left, min))
        return 1;

    if (root->val <= min)
        return 1;
    else
        min = root->val;

    if (traverse(root->right, min))
        return 1;

    return 0;
}

// Though INORDER of BST yields increasing values, We check all the values using prev stored temp value.

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    long long min = LONG_MIN;
    if (traverse(root, min))
        std::cout << "NO";
    else
        std::cout << "YES\n";
}