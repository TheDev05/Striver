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

// Left + Right + Root
void Postorder(std::vector<int> &num, TreeNode *root)
{
    if (root == NULL)
        return;

    std::stack<TreeNode *> st1, st2;
    st1.push(root);

    while (st1.size())
    {
        TreeNode *temp = st1.top();

        st2.push(temp);
        st1.pop();

        if (temp->left != NULL)
            st1.push(temp->left);
        if (temp->right != NULL)
            st1.push(temp->right);
    }

    while (st2.size())
    {
        num.push_back(st2.top()->val);
        st2.pop();
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::vector<int> num;
    Postorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}