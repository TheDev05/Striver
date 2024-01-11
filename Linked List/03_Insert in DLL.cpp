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
        this->next = this->prev = NULL;
    }
};

Node *traverse(std::vector<int> &num)
{
    Node *head = new Node(num[0]);
    Node *pointer = head;

    for (int i = 1; i < num.size(); i++)
    {
        Node *temp = new Node(num[i]);

        temp->prev = pointer;
        pointer->next = temp;

        pointer = temp;
    }

    return head;
}

Node *insertNode(Node *temp, int val)
{
    Node *prev = temp->prev;
    Node *next = temp;

    Node *newNode = new Node(val);
    Node *res = NULL;

    if (prev && next)
    {
        prev->next = newNode;
        newNode->prev = prev;

        newNode->next = next;
        next->prev = newNode;
    }
    else if (next)
        res = newNode;

    return res;
}

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    int index;
    std::cin >> index;

    int val;
    std::cin >> val;

    // Case(s): begin, mid, last

    Node *head = traverse(num);
    Node *temp = head, *prev = NULL;

    int pos = 0;
    while (temp)
    {
        if (pos == index)
        {
            Node *newHead = nodeInsert(temp, val);
            if (newHead)
            {
                newHead->next = head;
                head->prev = newHead;

                head = newHead;
                break;
            }
        }

        prev = temp;
        temp = temp->next;
        pos++;
    }

    if (temp == NULL)
    {
        Node *newNode = new Node(val);

        prev->next = newNode;
        newNode->prev = prev;
    }
}