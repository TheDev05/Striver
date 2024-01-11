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

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);

    Node *slow = head, *fast = head;
    Node *target = NULL;

    int count = 0;
    while (slow && fast)
    {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            break;

        if (target)
        {
            count++;

            if (target == slow)
                break;
        }

        if (slow == fast)
        {
            if (target == NULL)
                target = slow;
        }
    }

    std::cout << count;
}