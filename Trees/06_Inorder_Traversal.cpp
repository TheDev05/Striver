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

void Inorder(std::vector<int> &num, Node *root)
{
    if (root == NULL)
        return;

    Inorder(num, root->left);
    num.push_back(root->val);
    Inorder(num, root->right);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> num;
    Inorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}