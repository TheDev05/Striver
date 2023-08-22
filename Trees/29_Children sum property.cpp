#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int temp)
    {
        this->val = temp;
        this->left = this->right = NULL;
    }
};

void dfs(Node *root)
{
    if (root == NULL)
        return;

    dfs(root->left);
    dfs(root->right);

    std::cout << root->val << " ";
    return;
}

int traverse(Node *root)
{
    if (root == NULL)
        return 0;

    int left = 0, right = 0;

    if (root->left != NULL)
        left = root->left->val;
    if (root->right != NULL)
        right = root->right->val;

    if (root->val > left + right)
    {
        if (root->left != NULL)
            root->left->val = root->val;

        if (root->right != NULL)
            root->right->val = root->val;
    }
    else
        root->val = left + right;

    traverse(root->left);
    traverse(root->right);

    int sum = 0;
    if (root->left)
        sum += root->left->val;
    if (root->right)
        sum += root->right->val;

    if (root->left && root->right)
        root->val = sum;

    return 0;
}

int main()
{
    Node *root = new Node(40);

    root->left = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(5);

    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    traverse(root);
    dfs(root);
}