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

int main()
{
    int key;
    std::cin >> key;

    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);

    Node *tail = new Node(key);
    Node *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = tail;
}