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

int Preorder(Node *root, std::map<int, std::map<int, std::multiset<int>>> &num, int i, int j)
{
    if (root == NULL)
        return 0;

    num[i][j].insert(root->val);
    Preorder(root->left, num, i - 1, j + 1);
    Preorder(root->right, num, i + 1, j + 1);

    return 0;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::map<int, std::map<int, std::multiset<int>>> num;
    Preorder(root, num, 0, 0);

    std::vector<std::vector<int>> result;
    for (auto i : num)
    {
        std::vector<int> temp;
        for (auto j : i.second)
        {
            temp.insert(temp.end(), j.second.begin(), j.second.end());
        }
        
        result.push_back(temp);
    }
}