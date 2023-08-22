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

int traverse(Node *root, int &index)
{
    if (root == NULL)
        return 0;

    if (traverse(root->left, index))
        return 1;

    index = index - 1;
    if (index == 0)
    {
        index = root->val;
        return 1;
    }

    if (traverse(root->right, index))
        return 1;

    return 0;
}

int main()
{
    Node *root = new Node(2);

    root->left = new Node(1);
    root->right = new Node(3);

    int index;
    std::cin >> index;

    traverse(root, index);

    std::cout << index;
}