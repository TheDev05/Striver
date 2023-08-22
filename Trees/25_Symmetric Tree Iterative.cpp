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

bool traverse(TreeNode *root)
{
    if (root == NULL)
        return true;

    std::queue<TreeNode *> temp;
    temp.push(root);

    while (temp.size())
    {
        int size = temp.size();
        std::vector<int> local;

        for (int i = 0; i < size; i++)
        {
            TreeNode *inox = temp.front();
            temp.pop();

            if (inox->left != NULL)
            {
                temp.push(inox->left);
                local.push_back(inox->left->val);
            }
            else
                local.push_back(-1);

            if (inox->right != NULL)
            {
                temp.push(inox->right);
                local.push_back(inox->right->val);
            }
            else
                local.push_back(-1);
        }

        if (temp.size() & 1)
            return false;

        for (int i = 0; i < local.size() / 2; i++)
        {
            if (local[i] != local[local.size() - 1 - i])
                return false;
        }
    }

    return true;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << traverse(root);
}