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

std::map<int, int> inox;
TreeNode *traverse(std::vector<int> &in, std::vector<int> &pre, int i, int n)
{
    int temp = i;
    int min = INT_MAX, index = -1, val = 0;

    for (i; i < n; i++)
    {
        int j = inox[in[i]];
        
        if (j < min)
        {
            min = j;
            index = i;

            val = in[i];
        }
    }

    if (index == -1)
        return NULL;

    TreeNode *root = new TreeNode(val);
    root->left = traverse(in, pre, temp, index);
    root->right = traverse(in, pre, index + 1, n);

    return root;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> Inorder(n), Preorder(n);
    for (auto &i : Inorder)
        std::cin >> i;

    for (auto &i : Preorder)
        std::cin >> i;

    for (int i = 0; i < Preorder.size(); i++)
    {
        inox[Preorder[i]] = i;
    }

    traverse(Inorder, Preorder, 0, n);
}