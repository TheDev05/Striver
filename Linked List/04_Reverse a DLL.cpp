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

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *temp = head;

    Node *prev = NULL;
    while (temp)
    {
        // just swap previous and next
        Node *next = temp->next;

        temp->next = prev;
        temp->prev = next;

        prev = temp;
        temp = temp->prev;
    }

    // Now the last node is head;
    temp = prev;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}