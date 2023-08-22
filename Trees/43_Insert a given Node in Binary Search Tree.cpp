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

int main()
{
    Node *root = new Node(3);

    root->left = new Node(1);
    root->right = new Node(6);

    int target;
    std::cin >> target;

    Node *temp = root;

    Node *result = NULL;
    while (temp)
    {
        if (temp->val < target)
        {
            result = temp;
            temp = temp->right;
        }
        else
            temp = temp->left;
    }

    if (result)
    {
        Node *inox = result->right;
        result->right = new Node(target);

        result->right->right = inox;
    }
    else
    {
        Node *temp = new Node(target);
        temp->right = root;

        root = temp;
    }

    return root;
}