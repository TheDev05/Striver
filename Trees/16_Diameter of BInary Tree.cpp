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

int getDiameter(Node *root, int &max)
{
    if (root == NULL)
        return 0;

    int left = getDiameter(root->left, max);
    int right = getDiameter(root->right, max);

    max = std::max(max, left + right);
    return 1 + std::max(left, right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    int max = 0;
    getDiameter(root, max);

    std::cout << max;
}