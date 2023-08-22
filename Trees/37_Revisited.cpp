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

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    TreeNode *parent = root;
    while (parent)
    {
        if (parent->left == NULL)
        {
            std::cout << parent->val << " ";
            parent = parent->right;
        }
        else
        {
            TreeNode *temp = parent->left;
            while (temp->right && temp->right != parent)
            {
                temp = temp->right;
            }

            if (temp->right == NULL)
            {
                temp->right = parent;
                parent = parent->left;
            }

            if (temp->right == parent)
            {
                std::cout << parent->val << " ";
                parent = parent->right;

                // Loop is not allowed in trees, remove that temporary bridge
                temp->right = NULL;
            }
        }
    }
}