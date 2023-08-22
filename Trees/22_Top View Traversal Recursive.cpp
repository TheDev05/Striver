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

void Pre(Node *root, std::map<int, std::map<int, std::multiset<int>>> &num, int i, int j)
{
    if (root == NULL)
        return;

    num[i][j].insert(root->val);
    Pre(root->left, num, i - 1, j + 1);
    Pre(root->right, num, i + 1, j + 1);
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::map<int, std::map<int, std::multiset<int>>> num;
    Pre(root, num, 0, 0);

    std::vector<int> result;
    for (auto i : num)
    {
        for (auto j : i.second)
        {
            result.push_back(*j.second.begin());
            break;
        }
    }

    for (auto i : result)
        std::cout << i << " ";
}