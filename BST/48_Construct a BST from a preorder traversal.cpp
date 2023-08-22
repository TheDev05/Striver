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

TreeNode *traverse(std::vector<int> &preorder, std::vector<int> &inorder, std::map<int, int> &data, int left, int right, int index)
{
    if (right < left || index >= preorder.size())
        return NULL;

    int pos = data[preorder[index]];
    TreeNode *root = new TreeNode(preorder[index]);

    std::cout << preorder[index] << " ";

    root->left = traverse(preorder, inorder, data, left, pos - 1, index + 1);
    root->right = traverse(preorder, inorder, data, pos + 1, right, index + (pos - left) + 1);

    return root;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> preorder(n), inorder;
    for (auto &i : preorder)
        std::cin >> i;

    inorder = preorder;
    sort(inorder.begin(), inorder.end());

    std::map<int, int> data;
    for (int i = 0; i < inorder.size(); i++)
    {
        data[inorder[i]] = i;
    }

    std::cout << traverse(preorder, inorder, data, 0, inorder.size() - 1, 0)->right->val;
}