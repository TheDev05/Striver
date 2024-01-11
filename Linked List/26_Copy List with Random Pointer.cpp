#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next, *random;

    Node(int temp)
    {
        this->val = temp;
        this->next = this->random = nullptr;
    }
};

Node *traverse(std::vector<int> &num)
{
    Node *head = new Node(num[0]);
    Node *pointer = head;

    for (int i = 1; i < num.size(); i++)
    {
        Node *temp = new Node(num[i]);

        pointer->next = temp;
        temp->random = pointer;

        pointer = temp;
    }

    return head;
}

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *temp = head;

    std::map<Node *, Node *> data;
    while (temp)
    {
        Node *inox = new Node(temp->val);
        data[temp] = inox;
        temp = temp->next;
    }

    temp = head;

    while (temp)
    {
        Node *root = data[temp];
        Node *next = data[temp->next];
        Node *random = data[temp->random];

        root->next = next;
        root->random = random;

        temp = temp->next;
    }

    temp = data[head];
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}