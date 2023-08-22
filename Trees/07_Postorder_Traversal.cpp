#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int temp)
    {
        this->val = temp;
        this->left = this->right = NULL;
    }
};

void Postorder(std::vector<int> &num, TreeNode *root)
{
    if (root == NULL)
        return;

    Postorder(num, root->left);
    Postorder(num, root->right);

    num.push_back(root->val);
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::vector<int> num;
    Postorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}