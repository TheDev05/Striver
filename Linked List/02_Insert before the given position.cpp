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

Node *nodeInsert(Node *prev, Node *next, int key)
{
    Node *temp = new Node(key);

    if (prev && next || prev)
    {
        prev->next = temp;
        temp->next = next;

        return NULL;
    }
    else if (next)
        return temp;
}

int main()
{
    int index;
    std::cin >> index;

    int val;
    std::cin >> val;

    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);

    Node *temp = head;
    Node *prev = NULL;

    int count = 0;
    while (temp)
    {
        if (count++ == index)
        {
            Node *newHead = nodeInsert(prev, temp, val);
            if (newHead)
            {
                newHead->next = head;
                head = newHead;

                break;
            }
        }

        temp = temp->next;
        prev = temp;
    }

    if (index == n)
        prev->next = new Node(val);
}