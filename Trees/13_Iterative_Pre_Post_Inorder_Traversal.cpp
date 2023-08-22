#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int temp)
    {
        this->val = temp;
        this->left = this->right;
    }
};

void getList(std::vector<int> &Pre, std::vector<int> &Post, std::vector<int> &In, Node *root)
{
    if (root == NULL)
        return;

    std::stack<std::pair<Node *, int>> st;
    st.push({root, 1});

    while (st.size())
    {
        Node *temp = st.top().first;
        int count = st.top().second;

        if (count == 1)
        {
            Pre.push_back(temp->val);

            st.top().second++;
            if (temp->left != NULL)
                st.push({temp->left, 1});
        }
        else if (count == 2)
        {
            In.push_back(temp->val);

            st.top().second++;
            if (temp->right != NULL)
                st.push({temp->right, 1});
        }
        else
        {
            Post.push_back(temp->val);
            st.pop();
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> Pre, Post, In;
    getList(Pre, Post, In, root);

    for (auto i : Pre)
        std::cout << i << " ";
    std::cout << '\n';

    for (auto i : In)
        std::cout << i << " ";
    std::cout << '\n';

    for (auto i : Post)
        std::cout << i << " ";
    std::cout << '\n';
}