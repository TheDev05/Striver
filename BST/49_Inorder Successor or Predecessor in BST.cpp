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

void traverse(Node *root, int key, Node *&min, Node *&max)
{
    if (root == NULL)
        return;

    traverse(root->left, key, min, max);

    if (root->val < key)
        min = root;
    if (root->val > key && max == NULL)
        max = root;

    traverse(root->right, key, min, max);

    return;
}

int main()
{
    Node *root = new Node(2);

    root->left = new Node(1);
    root->right = new Node(4);

    int key;
    std::cin >> key;

    Node *min = NULL, *max = NULL;
    traverse(root, key, min, max);

    std::cout << min->val << " " << max->val;
}