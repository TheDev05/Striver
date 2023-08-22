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
        this->left = this->right;
    }
};

// Root + Left + Right
// Left + Root + Right
// Left + Right + Root

void getList(std::vector<int> &Pre, std::vector<int> &Post, std::vector<int> &In, Node *root)
{
    if (root == NULL)
        return;

    // Root + Left + Right :  store before left & right call
    Pre.push_back(root->val);
    getList(Pre, Post, In, root->left);

    // Left + Root + Right : store before right & after left
    In.push_back(root->val);
    getList(Pre, Post, In, root->right);

    // Left + Right + Root : store after left & right
    Post.push_back(root->val);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> Pre, Post, In;
    getList(Pre, Post, In, root);

    for (auto i : Pre)
        std::cout << i << " ";
    std::cout << '\n';

    for (auto i : In)
        std::cout << i << " ";
    std::cout << '\n';

    for (auto i : Post)
        std::cout << i << " ";
    std::cout << '\n';
}