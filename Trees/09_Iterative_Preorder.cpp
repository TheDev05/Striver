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

// Root + Left + Right

void Preorder(std::vector<int> &num, TreeNode *root)
{
    if (root == NULL)
        return;

    std::stack<TreeNode *> q;
    q.push(root);

    while (q.size())
    {
        TreeNode *temp = q.top();
        q.pop();

        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left != NULL)
            q.push(temp->left);

        num.push_back(temp->val);
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::vector<int> num;
    Preorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}