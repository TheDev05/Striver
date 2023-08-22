#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = this->right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;

    std::cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    preorder(root);
}