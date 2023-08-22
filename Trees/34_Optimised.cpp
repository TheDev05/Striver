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
        this->val = temp;
    }
};

std::map<int, int> inox;
TreeNode *traverse(std::vector<int> &pre, int preStart, int preEnd, std::vector<int> &in, int inStart, int inEnd)
{
    if (preEnd < preStart || inEnd < inStart)
        return NULL;

    int rootIndex = inox[pre[preStart]];
    TreeNode *root = new TreeNode(in[rootIndex]);

    root->left = traverse(pre, preStart + 1, preStart + (rootIndex - inStart), in, inStart, rootIndex - 1);
    root->right = traverse(pre, preStart + 1 + (rootIndex - inStart), preEnd, in, rootIndex + 1, inEnd);

    return root;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> pre(n), in(n);
    for (auto &i : in)
        std::cin >> i;

    for (auto &i : pre)
        std::cin >> i;

    for (int i = 0; i < in.size(); i++)
    {
        inox[in[i]] = i;
    }

    traverse(pre, 0, n - 1, in, 0, n - 1);
}