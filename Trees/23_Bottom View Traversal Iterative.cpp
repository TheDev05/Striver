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

void traverse(Node *root, std::map<int, std::map<int, int>> &num)
{
    if (root == NULL)
        return;

    std::queue<std::pair<Node *, std::pair<int, int>>> temp;
    temp.push({root, {0, 0}});

    while (temp.size())
    {
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            auto local = temp.front();
            temp.pop();

            if (local.first->left != NULL)
                temp.push({local.first->left, {local.second.first - 1, local.second.second + 1}});
            if (local.first->right != NULL)
                temp.push({local.first->right, {local.second.first + 1, local.second.second + 1}});
            num[local.second.first][local.second.second] = local.first->val;
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::map<int, std::map<int, int>> num;
    traverse(root, num);

    std::vector<int> result;
    for (auto i : num)
    {
        auto it = i.second.rbegin();
        result.push_back(it->second);
    }

    for (auto i : result)
        std::cout << i << " ";
}