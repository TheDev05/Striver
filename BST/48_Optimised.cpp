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

TreeNode *validate(std::vector<int> &preorder, int &index, long long left, long long right)
{
    if (index >= preorder.size())
        return NULL;

    if (preorder[index] > left && preorder[index] < right)
    {
        TreeNode *root = new TreeNode(preorder[index]);

        index = index + 1;

        root->left = validate(preorder, index, left, root->val);
        root->right = validate(preorder, index, root->val, right);

        return root;
    }
    else
        return NULL;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> preorder(n);
    for (auto &i : preorder)
        std::cin >> i;

    long long left = LONG_MIN, right = LONG_MAX;
    int index = 0;

    std::cout << validate(preorder, index, left, right);
}