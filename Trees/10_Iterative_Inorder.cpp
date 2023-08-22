#include <bits/stdc++.h>
using namespace std;

// we traverse all unvisited nodes first in order of (Left + Root + Right) then when encouter with visited nodes, we simply print them.

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int temp)
    {
        this->val = temp;
        this->left = this->right = NULL;
    }
};

void Inorder(std::vector<int> &num, Node *root)
{
    if (root == NULL)
        return;

    std::stack<Node *> st;
    Node *temp = root;

    st.push(temp);
    while (st.size())
    {
        if (temp == NULL)
        {
            temp = st.top();
            st.pop();

            num.push_back(temp->val);
            temp = temp->right;
        }
        else
        {
            st.push(temp);
            temp = temp->left;
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> num;
    Inorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}