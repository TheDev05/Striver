#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next, *prev;

    Node(int temp)
    {
        this->val = temp;
        this->next = this->prev = nullptr;
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
        temp->prev = pointer;

        pointer = temp;
    }

    return head;
}

Node* traverse(Node *head, Node *prev)
{
    if (head == NULL)
        return prev;

    Node *next = head->next;
    head->next = prev;
    prev = head;

    return traverse(next, prev);
}

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *prev = traverse(head, NULL);
    
    while (prev)
    {
        std::cout << prev->val << " ";
        prev = prev->next;
    }
}