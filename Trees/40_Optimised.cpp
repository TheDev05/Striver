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
        this->left = this->right;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int target;
    std::cin >> target;

    while (root && root->val != target)
    {
        if (root->val > target)
            root = root->left;
        else
            root = root->right;
    }

    return root;
}