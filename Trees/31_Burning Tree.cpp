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
        this->left = this->right = NULL;
    }
};

Node *dfs(Node *root, int k)
{
    if (root == NULL)
        return NULL;

    if (root->data == k)
        return root;

    Node *data1 = dfs(root->left, k);
    Node *data2 = dfs(root->right, k);

    if (data1 != NULL)
        return data1;
    if (data2 != NULL)
        return data2;

    return NULL;
}

void traverse(Node *root, std::map<Node *, Node *> &parent)
{
    if (root == NULL)
        return;

    std::queue<Node *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
            {
                inox.push(temp->left);
                parent[temp->left] = temp;
            }

            if (temp->right != NULL)
            {
                inox.push(temp->right);
                parent[temp->right] = temp;
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    int k = 3;
    Node *start = dfs(root, k);

    std::map<Node *, Node *> parent;
    traverse(root, parent);

    std::queue<std::pair<Node *, int>> store;
    std::set<Node *> skip;

    store.push({start, 0});

    int count = 0;
    while (store.size())
    {
        int size = store.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = store.front().first;
            int dash = store.front().second;

            store.pop();

            if (temp->left != NULL && !skip.count(temp->left))
                store.push({temp->left, dash + 1});
            if (temp->right != NULL && !skip.count(temp->right))
                store.push({temp->right, dash + 1});
            if (parent.count(temp) && !skip.count(parent[temp]))
                store.push({parent[temp], dash + 1});

            skip.insert(temp);
            count = std::max(count, dash);
        }
    }

    std::cout << count;
}