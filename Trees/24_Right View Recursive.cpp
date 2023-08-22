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

void traverse(Node *root, std::map<int, int> &num, int j)
{
    if (root == NULL)
        return;

    if (store.count(j) == false)
        store[j] = root->val;

    traverse(root->left, num, j + 1);
    traverse(root->right, num, j + 1);

    return;
}

int main()
{
    Node *root = new Node(0);

    root->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    root->right = new Node(2);
    root->right->left = new Node(4);
    root->right->left->left = new Node(9);
    root->right->left->left->left = new Node(10);

    std::map<int, int> num;
    traverse(root, num, 0);

    std::vector<int> result;
    for (auto i : num)
        result.push_back(i.second);

    for (auto i : result)
        std::cout << i << " ";
}