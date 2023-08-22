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

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    int key;
    std::cin >> key;

    Node *ok = NULL;
    while (root)
    {
        if (root->val == key)
        {
            ok = root;
            break;
        }
        else if (root->val > key)
            root = root->left;
        else
            root = root->right;
    }

    std::cout << ok->val;
}