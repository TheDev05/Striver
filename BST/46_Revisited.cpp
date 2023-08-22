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

bool validate(TreeNode *root, long long left, long long right)
{
    if (root == NULL)
        return 0;

    if (root->val <= left || root->val >= right)
        return 1;

    if (validate(root->left, left, root->val))
        return 1;
    if (validate(root->right, root->val, right))
        return 1;

    return 0;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    long long left = LONG_MIN, right = LONG_MAX;
    std::cout << validate(root, left, right);
}