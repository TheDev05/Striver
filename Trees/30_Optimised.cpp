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

void traverse(TreeNode *root, std::map<TreeNode *, TreeNode *> &parent)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
            {
                parent[temp->left] = temp;
                inox.push(temp->left);
            }

            if (temp->right != NULL)
            {
                parent[temp->right] = temp;
                inox.push(temp->right);
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::map<TreeNode *, TreeNode *> parent;
    traverse(root, parent);

    int k = 1;
    std::queue<TreeNode *> inox;
    std::set<TreeNode *> skip;

    inox.push(root);
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL && !skip.count(temp->left))
                inox.push(temp->left);
            if (temp->right != NULL && !skip.count(temp->right))
                inox.push(temp->right);
            if (parent.count(temp) && !skip.count(parent[temp]))
                inox.push(parent[temp]);

            skip.insert(temp);
        }

        k--;

        if (k == 0)
            break;
    }

    std::vector<int> result;
    while (inox.size())
    {
        result.push_back(inox.front()->val);
        inox.pop();
    }

    for (auto i : result)
        std::cout << i << " ";
}