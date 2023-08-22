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

void traverse(Node *root, std::vector<int> &num, int level)
{
    if (root == NULL)
        return;

    if (level != num.size())
        num.push_back(root->val);

    traverse(root->right, num, level + 1);
    traverse(root->left, num, level + 1);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> num;
    traverse(root, num, 1);

    for (auto i : num)
        std::cout << i << " ";
}