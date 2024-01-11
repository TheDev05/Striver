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

int getLength(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    int k;
    std::cin >> k;

    ListNode *head = traverse(num);
    ListNode *temp = head;

    int length = getLength(head);
    if (k > length)
        k = k % length;

    int delta = length - k;
    ListNode *newHead = NULL;

    int count = 1;
    while (temp->next)
    {
        if (count == delta)
        {
            ListNode *res = temp->next;
            temp->next = NULL;
            temp = res;

            if (newHead == NULL)
                newHead = temp;
        }
        else
            temp = temp->next;

        count++;
    }

    temp->next = head;
    temp = newHead;

    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}
