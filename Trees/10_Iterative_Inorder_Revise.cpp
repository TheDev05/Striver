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

void Inorder(std::vector<int> &num, TreeNode *root)
{
    std::stack<TreeNode *> st;
    TreeNode *temp = root;

    while (1)
    {
        if (temp == NULL)
        {
            if (st.empty())
                break;

            TreeNode *alt = st.top();
            st.pop();

            temp = alt->right;
            num.push_back(alt->val);
        }
        else
        {
            st.push(temp);
            temp = temp->left;
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::vector<int> num;
    Inorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}