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

void left(Node *root, std::vector<int> &leftBox)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    leftBox.push_back(root->val);
    if (root->left == NULL)
        left(root->right, leftBox);
    else
        left(root->left, leftBox);

    return;
}

void leaf(Node *root, std::vector<int> &leafBox)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        leafBox.push_back(root->val);

    leaf(root->left, leafBox);
    leaf(root->right, leafBox);

    return;
}

void right(Node *root, std::vector<int> &leftBox)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    leftBox.push_back(root->val);
    if (root->right == NULL)
        right(root->left, leftBox);
    else
        right(root->right, leftBox);

    return;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);

    std::vector<int> leftBox, rightBox;
    // if(root==NULL) return leftBox;
    leftBox.push_back(root->val);

    // if(root->left==NULL && root->right==NULL) return leftBox;

    left(root->left, leftBox);
    leaf(root, leftBox);
    right(root, rightBox);

    reverse(rightBox.begin(), rightBox.end());
    for (auto i : rightBox)
        leftBox.push_back(i);
}