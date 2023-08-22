#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left, *right;

    Node(int temp)
    {
        this->key = temp;
        this->left = this->right = NULL;
    }
};

Node *left(Node *root, Node *&pre, int key, int &min)
{
    if (root == NULL)
        return NULL;

    if (root->key < key)
    {
        if (root->key > min)
        {
            min = root->key;
            pre = root;
        }

        right(root->left, pre, key, min);
    }
    else
        left(root->right, pre, key, min);

    return NULL;
}

Node *right(Node *root, Node *&suc, int key, int &max)
{
    if (root == NULL)
        return NULL;

    if (root->key > key)
    {
        if (root->key < max)
        {
            max = root->key;
            suc = root;
        }

        right(root->left, suc, key, max);
    }
    else
        right(root->right, suc, key, max);

    return NULL;
}

int main()
{
    Node *root = new Node(2);

    root->left = new Node(1);
    root->right = new Node(4);

    int key;
    std::cin >> key;

    Node *pre, *suc;

    int min = INT_MIN, max = INT_MAX;

    left(root, pre, key, min);
    right(root, suc, key, max);

    std::cout << max << " ";
}