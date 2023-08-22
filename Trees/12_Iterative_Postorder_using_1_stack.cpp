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
        this->left = this->right = NULL;
    }
};

// Left + Right + Root

void Postorder(std::vector<int> &num, Node *root)
{
    if (root == NULL)
        return;

    std::stack<Node *> st;
    Node *curr = root;

    while (st.size() || curr != NULL)
    {
        if (curr == NULL)
        {
            Node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                num.push_back(temp->val);
                st.pop();

                while (st.size() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();

                    num.push_back(temp->val);
                }
            }
            else
                curr = temp;
        }
        else
        {
            st.push(curr);
            curr = curr->left;
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    std::vector<int> num;
    Postorder(num, root);

    for (auto i : num)
        std::cout << i << " ";
}