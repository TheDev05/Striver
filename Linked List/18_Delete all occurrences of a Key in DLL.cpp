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

Node *deleteNode(Node *head)
{
    Node *temp = head;
    Node *prev = temp->prev, *next = temp->next;

    if (prev && next)
    {
        prev->next = next;
        next->prev = prev;
    }
    else if (prev)
        prev->next = NULL;
    else if (next)
        next->prev = NULL;
    else
        return NULL;

    delete temp;
    return next;
}

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    int key;
    std::cin >> key;

    Node *head = traverse(num);
    Node *temp = head;

    while (temp)
    {
        if (temp->val == key)
        {
            bool ok = false;
            if (head->val == key)
                ok = true;

            temp = deleteNode(temp);
            if (ok)
                head = temp;
        }
        else
            temp = temp->next;
    }

    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
}