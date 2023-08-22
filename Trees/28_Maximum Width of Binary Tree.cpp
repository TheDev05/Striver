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

int traverse(Node *root)
{
    if (root == NULL)
        return 0;

    std::queue<Node *> temp;
    std::map<Node *, int> data;

    temp.push(root);
    data[root] = 1;

    int max = 1;
    while (temp.size())
    {
        int size = temp.size();
        max = (data.rbegin()->second - data.begin()->second) + 1;

        for (int i = 0; i < size; i++)
        {
            Node *local = temp.front();
            temp.pop();

            if (local->left != NULL)
            {
                data[local->left] = 2 * data[local];
                temp.push(local->left);
            }

            if (local->right != NULL)
            {
                data[local->right] = (2 * data[local]) + 1;
                temp.push(local->right);
            }

            data.erase(local);
        }
    }

    return max;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(3);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->right = new Node(2);
    root->right->right = new Node(9);

    std::cout << traverse(root);
}