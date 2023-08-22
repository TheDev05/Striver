#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int temp)
    {
        this->left = this->right = NULL;
        this->val = temp;
    }
};

int main()
{
    Node *root = new Node(2);

    root->left = new Node(1);
    root->right = new Node(3);

    int key;
    std::cin >> key;

    Node *temp = root;

    while (temp)
    {
        if (temp->val > key)
        {
            if (temp->left == NULL)
            {
                temp->left = new Node(key);
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = new Node(key);
                break;
            }
            else
                temp = temp->right;
        }
    }

    if (root->right->right)
        std::cout << root->right->right->val;
}