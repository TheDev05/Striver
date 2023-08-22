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

void fillLeft(std::stack<TreeNode *> &left, TreeNode *root)
{
    if (root == NULL)
        return;

    while (root)
    {
        left.push(root);
        root = root->left;
    }
}

void fillRight(std::stack<TreeNode *> &right, TreeNode *root)
{
    if (root == NULL)
        return;

    while (root)
    {
        right.push(root);
        root = root->right;
    }
}

int main()
{
    TreeNode *root = new TreeNode(0);

    root->left = new TreeNode(-3);
    root->left->left = new TreeNode(-4);

    root->right = new TreeNode(2);
    root->right->left = new TreeNode(1);

    int key;
    std::cin >> key;

    std::stack<TreeNode *> left, right;

    fillLeft(left, root);
    fillRight(right, root);

    int temp1 = 0, temp2 = 0;

    TreeNode *dash1 = right.top();
    TreeNode *dash2 = left.top();

    temp1 = dash1->val;
    temp2 = dash2->val;

    left.pop();
    right.pop();

    fillLeft(left, dash2->right);
    fillRight(right, dash1->left);

    bool ok = false;
    while (temp2 < temp1)
    {
        int sum = temp1 + temp2;
        if (sum == key)
        {
            ok = true;
            break;
        }
        else if (sum > key)
        {
            TreeNode *val1 = right.top();
            temp1 = val1->val;

            right.pop();
            fillRight(right, val1->left);
        }
        else
        {
            TreeNode *val2 = left.top();
            temp2 = val2->val;

            left.pop();
            fillLeft(left, val2->right);
        }
    }

    if (ok)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}