#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next, *prev;

    ListNode(int temp)
    {
        this->val = temp;
        this->next = this->prev = nullptr;
    }
};

ListNode *traverse(std::vector<int> &num)
{
    ListNode *head = new ListNode(num[0]);
    ListNode *pointer = head;

    for (int i = 1; i < num.size(); i++)
    {
        ListNode *temp = new ListNode(num[i]);

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

    ListNode *head = traverse(num);
    ListNode *evenStart = head->next;

    ListNode *temp = head;
    ListNode *lastNode = NULL;

    // 1 2 3 4 5

    int index = 1;
    while (temp)
    {
        ListNode *next = temp->next;
        if (index & 1)
        {
            lastNode = temp;

            if (temp->next && temp->next->next)
                temp->next = temp->next->next;
            else if (temp->next)
                temp->next = NULL;
        }
        else
        {
            if (temp->next && temp->next->next)
                temp->next = temp->next->next;
            else if (temp->next)
                temp->next = NULL;
        }

        index++;
        temp = next;
    }

    lastNode->next = evenStart;
    temp = head;

    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}