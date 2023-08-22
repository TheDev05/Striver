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

bool read(TreeNode *root, int key)
{
    if (root == NULL)
        return false;

    while (root)
    {
        if (root->val == key)
            return true;

        if (root->val > key)
            root = root->left;
        else
            root = root->right;
    }

    return false;
}

bool traverse(TreeNode *res, TreeNode *root, int key)
{
    if (root == NULL)
        return false;

    int delta = key - root->val;
    if (delta != root->val && read(res, delta))
        return true;

    if (traverse(res, root->left, key))
        return true;
    if (traverse(res, root->right, key))
        return true;

    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int key;
    std::cin >> key;

    std::cout << traverse(root, root, key);
}