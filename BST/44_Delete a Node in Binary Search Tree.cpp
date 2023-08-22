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

TreeNode *update(TreeNode *inox)
{
    if (inox->left == NULL)
    {
        inox = inox->right;
    }
    else if (inox->right == NULL)
    {
        inox = inox->left;
    }
    else
    {
        TreeNode *dash = inox->left;
        while (dash->right)
        {
            dash = dash->right;
        }

        if (dash->right == NULL)
            dash->right = inox->right;
        inox = inox->left;
    }

    return inox;
}

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    int key;
    std::cin >> key;

    TreeNode *temp = root;

    if (key = temp->val)
        return update(temp);

    while (temp)
    {
        if (temp->val < key)
        {
            if (temp->right && temp->right->val == key)
            {
                temp->right = update(temp->right);
                break;
            }
            else
                temp = temp->right;
        }
        else
        {
            if (temp->left && temp->left->val == key)
            {
                temp->left = update(temp->left);
                break;
            }
            else
                temp = temp->left;
        }
    }
}