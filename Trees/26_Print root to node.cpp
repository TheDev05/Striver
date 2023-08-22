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

bool traverse(Node *root, int target, std::vector<int> &num)
{
    if (root == NULL)
        return false;

    num.push_back(root->val);
    if (root->val == target)
        return true;

    if (traverse(root->left, target, num))
        return true;
    if (traverse(root->right, target, num))
        return true;

    num.pop_back();

    return false;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    int target;
    std::cin >> target;

    std::vector<int> num;
    traverse(root, target, num);

    for (auto i : num)
        std::cout << i << " ";
}