#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int temp)
    {
        this->left = this->right = NULL;
        this->val = NULL;
    }
};

std::vector<int> traverse(TreeNode *root)
{
    std::vector<int> num;
    TreeNode *current = root;

    while (current != NULL)
    {
        if (current->left == NULL)
        {
            num.push_back(current->val);
            current = current->right;
        }
        else
        {
            TreeNode *temp = current->left;
            while (temp->right != NULL && temp->right != current)
            {
                temp = temp->right;
            }

            if (temp->right == NULL)
            {
                temp->right = current;
                current = current->left;
            }
            else if (temp->right == current)
            {
                num.push_back(current->val);
                current = current->right;
                temp->right = NULL;
            }
        }
    }

    return num;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    traverse(root);
}