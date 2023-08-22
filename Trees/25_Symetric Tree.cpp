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

bool traverse(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->val != root2->val)
        return false;

    if (traverse(root1->left, root2->right) == false)
        return false;
    if (traverse(root1->right, root2->left) == false)
        return false;

    return true;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    std::cout << traverse(root->left, root->right);
}