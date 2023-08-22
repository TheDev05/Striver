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

    root->left = new TreeNode(0);
    root->right = new TreeNode(3);

    int target;
    std::cin >> target;

    int inox = -1;
    while (root)
    {
        if (root->val == target)
        {
            inox = target;
            break;
        }
        else if (root->val < target)
        {
            inox = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }

    std::cout << inox;
}