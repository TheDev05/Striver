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

ListNode *reverseNode(ListNode *temp)
{
    ListNode *prev = NULL;
    while (temp)
    {
        ListNode *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

int main()
{
    std::vector<int> num = {1, 2, 2, 1};
    // std::iota(begin(num), end(num), 1);

    ListNode *head = traverse(num);
    ListNode *hare = head, *tortoise = head;

    ListNode *mid = NULL;
    while (1)
    {
        mid = hare;
        if (hare->next && tortoise->next && tortoise->next->next)
            hare = hare->next,
            tortoise = tortoise->next->next;
        else
            break;
    }

    hare = hare->next;

    ListNode *newHead = reverseNode(hare);
    ListNode *temp1 = head, *temp2 = newHead;

    while (temp1 && temp2)
    {
        if (temp1->val != temp2->val)
            std::cout << "NO";

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    std::cout << "YES";
}