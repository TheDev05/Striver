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

int getMaxPathSum(Node *root, int &max)
{
    if (root == NULL)
        return 0;

    int left = getMaxPathSum(root->left, max);
    int right = getMaxPathSum(root->right, max);

    if (left < 0)
        left = 0;
    if (right < 0)
        right = 0;

    max = std::max(max, left + right + root->val);
    return std::max(left, right) + root->val;
}

int main()
{
    Node *root = new Node(-2);

    root->left = new Node(-1);
    root->right = new Node(-3);

    int max = INT_MIN;
    getMaxPathSum(root, max);

    std::cout << max;
}