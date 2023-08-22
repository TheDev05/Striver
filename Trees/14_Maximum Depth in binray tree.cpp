#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int temp)
    {
        this->val = temp;
        this->left = this->right = NULL;
    }
};

int getDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int left = getDepth(root->left);
    int right = getDepth(root->right);

    return 1 + std::max(left, right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::cout << getDepth(root);
}