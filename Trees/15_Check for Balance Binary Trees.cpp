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

int check(Node *root)
{
    if (root == NULL)
        return 0;

    int left = check(root->left);
    int right = check(root->right);

    if (abs(left - right) > 1 || left == -1 || right == -1)
        return -1;

    return 1 + std::max(left, right);
}

// Balanced Tree: the diffrence between left height and right height of any node have to 0 or 1.

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    if (check(root) == -1)
        std::cout << "0";
    else
        std::cout << "1";
}