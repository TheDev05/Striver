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
        this->left = this->right;
    }
};

void InsertNodes(TreeNode *root, std::stack<TreeNode *> &st, bool right)
{
    if (root == NULL)
        return;

    while (root)
    {
        st.push(root);

        if (right)
            root = root->right;
        else
            root = root->left;
    }
}

int Traverse(std::stack<TreeNode *> &st, bool right)
{
    TreeNode *temp = st.top();
    st.pop();

    if (right)
        InsertNodes(temp->left, st, right);
    else
        InsertNodes(temp->right, st, right);

    return temp->val;
}

int main()
{
    TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    int key;
    std::cin >> key;

    std::stack<TreeNode *> st1, st2;

    InsertNodes(root, st1, 0);
    InsertNodes(root, st2, 1);

    int left = 0, right = 0;

    left = Traverse(st1, 0);
    right = Traverse(st2, 1);

    bool ok = false;
    while (left < right)
    {
        if (left + right == key)
            ok = true;
        if (left + right < key)
            left = Traverse(st1, 0);
        else
            right = Traverse(st2, 1);
    }

    if (ok)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
}