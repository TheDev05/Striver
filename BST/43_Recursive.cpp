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

int insert(TreeNode *root, int key)
{
    if (root->val < key)
    {
        if (root->right == NULL)
        {
            root->right = new TreeNode(key);
            return 1;
        }

        if (insert(root->right, key))
            return 1;
    }
    else
    {
        if (root->left == NULL)
        {
            root->left = new TreeNode(key);
            return 1;
        }

        if (insert(root->left, key))
            return 1;
    }

    return 0;
}

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    int key;
    std::cin >> key;

    insert(root, key);

    // return root;
}