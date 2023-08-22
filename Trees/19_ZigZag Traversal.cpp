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

void Levelorder(TreeNode *root, std::vector<std::vector<int>> &num)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> storage;
    storage.push(root);

    int toggle = 0;
    while (storage.size())
    {
        int size = storage.size();
        std::vector<int> temp(size);

        int index = 0;
        if (toggle & 1)
            index = 0;
        else
            index = size - 1;

        for (int i = 0; i < size; i++)
        {
            TreeNode *local = storage.front();
            storage.pop();

            if (local->left != NULL)
                storage.push(local->left);
            if (local->right != NULL)
                storage.push(local->right);

            temp[abs((size - 1) - index)] = local->val;
            index++;
        }

        num.push_back(temp);
        toggle++;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::vector<std::vector<int>> num;
    Levelorder(root, num);

    for (auto i : num)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << '\n';
    }
}