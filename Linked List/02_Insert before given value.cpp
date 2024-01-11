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

Node *nodeInsert(Node *prev, Node *curr, int val)
{
    Node *temp = new Node(val);
    if (prev && curr)
    {
        prev->next = temp;
        temp->next = curr;

        return NULL;
    }
    else if (curr)
        return temp;
}

int main()
{
    int val;
    std::cin >> val;

    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *temp = head, *prev = NULL;

    while (temp)
    {
        if (temp->val == val)
        {
            Node *newHead = nodeInsert(prev, temp, val);
            if (newHead)
            {
                newHead->next = head;
                head = newHead;

                break;
            }
        }

        prev = temp;
        temp = temp->next;
    }
}
