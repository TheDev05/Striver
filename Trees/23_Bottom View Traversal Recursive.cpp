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

void traverse(Node *root, std::map<int, std::map<int, int>> &num, int i, int j)
{
    if (root == NULL)
        return;

    // For many value at (j) : As we are traversing preorder the right value is inserted as last to our DS
    num[i][j] = (root->val);
    traverse(root->left, num, i - 1, j + 1);
    traverse(root->right, num, i + 1, j + 1);

    return;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    std::map<int, std::map<int, int>> num;
    traverse(root, num, 0, 0);

    std::vector<int> result;
    for (auto i : num)
    {
        auto temp = i.second.rbegin();
        result.push_back(temp->second);
    }

    for (auto i : result)
        std::cout << i << " ";
}
