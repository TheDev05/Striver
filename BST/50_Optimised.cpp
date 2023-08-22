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

void pushLeft(TreeNode *root, std::stack<TreeNode *> &st)
{
    if (root == NULL)
        return;

    while (root)
    {
        st.push(root);
        root = root->left;
    }
}

class BSTIterator
{
    std::stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root, st);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        if (temp->right)
            pushLeft(temp->right, st);

        return temp->val;
    }

    bool hasNext()
    {
        return st.empty() ? false : true;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    BSTIterator obj(root);
}