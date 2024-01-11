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
    ListNode *temp = head;

    ListNode *odd = new ListNode(-1);
    ListNode *even = new ListNode(-1);

    ListNode *pointer2odd = odd;
    ListNode *pointer2even = even;

    int index = 1;
    while (temp)
    {
        if (index & 1)
        {
            ListNode *newNode = new ListNode(temp->val);
            pointer2odd->next = newNode;
            pointer2odd = newNode;
        }
        else
        {
            ListNode *newNode = new ListNode(temp->val);
            pointer2even->next = newNode;
            pointer2even = newNode;
        }

        index++;
        temp = temp->next;
    }

    if (even)
        pointer2odd->next = even->next;

    temp = odd->next;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}