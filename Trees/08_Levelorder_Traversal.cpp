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

void Levelorder(std::vector<std::vector<int>> &num, TreeNode *root)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> q;
    q.push(root);

    while (q.size())
    {
        std::vector<int> temp;
        int total = q.size();

        for (int i = 0; i < total; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            temp.push_back(node->val);
        }

        num.push_back(temp);
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::vector<std::vector<int>> num;
    Levelorder(num, root);

    for (auto i : num)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}