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

void traverse(TreeNode *root, std::vector<int> &num)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> temp;
    temp.push(root);

    while (temp.size())
    {
        int size = temp.size();
        int last = 0;

        for (int i = 0; i < size; i++)
        {
            TreeNode *local = temp.front();
            temp.pop();

            if (local->left != NULL)
                temp.push(local->left);
            if (local->right != NULL)
                temp.push(local->right);

            last = local->val;
        }

        num.push_back(last);
    }
}

int main()
{
    TreeNode *root = new TreeNode(0);

    root->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(9);
    root->right->left->left->left = new TreeNode(10);

    std::vector<int> num;
    traverse(root, num);

    for (auto i : num)
        std::cout << i << " ";
}