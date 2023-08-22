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

int traverse(TreeNode *root, TreeNode *target, std::vector<TreeNode *> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root);
    if (root == target)
        return true;

    if (traverse(root->left, target, path))
        return true;
    if (traverse(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    // accepting values
    TreeNode *target1, *target2;

    target1 = new TreeNode(1);
    target2 = new TreeNode(2);

    std::vector<TreeNode *> path1, path2;

    traverse(root, target1, path1);
    traverse(root, target2, path2);

    std::set<TreeNode *> data;
    for (auto i : path1)
        data.insert(i);

    TreeNode *local = NULL;
    for (int i = 0; i < path2.size(); i++)
    {
        if (data.count(path2[i]))
            local = path2[i];
    }

    std::cout << local;
}