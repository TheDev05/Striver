#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int temp)
    {
        this->val = temp;
        this->next = NULL;
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
        pointer = temp;
    }

    return head;
}

Node *deleteTail(Node *head)
{
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    if (head == NULL)
        return NULL;

    Node *prev, *curr = head;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    delete curr;

    return head;
}

int main()
{
    std::vector<int> num(1);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *newHead = deleteTail(head);

    Node *temp = newHead;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}