#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int temp)
    {
        this->data = temp;
        this->left = this->right;
    }
};

void level(Node *root, std::map<int, std::map<int, std::multiset<int>>> &num)
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
            auto inox = temp.front();
            temp.pop();

            if (inox.first->left != NULL)
                temp.push({inox.first->left, {inox.second.first - 1, inox.second.second + 1}});
            if (inox.first->right != NULL)
                temp.push({inox.first->right, {inox.second.first + 1, inox.second.second + 1}});

            num[inox.second.first][inox.second.second].insert(inox.first->data);
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::map<int, std::map<int, std::multiset<int>>> num;
    level(root, num);

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