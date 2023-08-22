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

int inox = 0;
int traverse(Node *root)
{
    if (root == NULL)
        return 0;

    int left = traverse(root->left);
    int right = traverse(root->right);

    return left + right + 1;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(4);

    std::cout << traverse(root);
}