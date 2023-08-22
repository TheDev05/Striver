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

std::string transformText(TreeNode *root)
{
    std::string text = "";

    if (root == NULL)
        return text;

    std::queue<TreeNode *> inox;

    inox.push(root);
    text += to_string(root->val);

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            text += ".";
            if (temp->left != NULL)
            {
                inox.push(temp->left);
                text += to_string(temp->left->val);
            }
            else
                text += 'X';

            text += ".";
            if (temp->right != NULL)
            {
                inox.push(temp->right);
                text += to_string(temp->right->val);
            }
            else
                text += 'X';
        }
    }

    // std::cout << text << '\n';
    return text;
}

TreeNode *transformTree(std::string text)
{
    std::string temp;

    std::stringstream ss(text);
    getline(ss, temp, '.');

    TreeNode *root = new TreeNode(stoi(temp));

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *snap = inox.front();
            inox.pop();

            getline(ss, temp, '.');
            if (temp != "X")
            {
                snap->left = new TreeNode(stoi(temp));
                inox.push(snap->left);
            }
            else
                snap->left = NULL;

            getline(ss, temp, '.');
            if (temp != "X")
            {
                snap->right = new TreeNode(stoi(temp));
                inox.push(snap->right);
            }
            else
                snap->right = NULL;
        }
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);

    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(3);

    std::cout << transformText(root);
}