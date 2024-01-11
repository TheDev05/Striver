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
        this->next = this->prev = NULL;
    }
};

ListNode *traverse(std::vector<int> &num)
{
    ListNode *head = new ListNode(num[0]);
    ListNode *pointer = head;

    for (int i = 1; i < num.size(); i++)
    {
        ListNode *temp = new ListNode(num[i]);

        temp->prev = pointer;
        pointer->next = temp;

        pointer = temp;
    }

    return head;
}

ListNode *getMiddle(ListNode *head)
{
    ListNode *temp = head, *prev = head;
    ListNode *fast = head, *slow = head;

    while (1)
    {
        if (fast->next == NULL)
            return prev;
        if (fast->next->next == NULL)
            return slow;

        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return NULL;
}

int main()
{
    std::vector<int> num(1);
    std::iota(begin(num), end(num), 1);

    ListNode *head = traverse(num);

    ListNode *midPrev = getMiddle(head);
    ListNode *mid = midPrev->next;
    ListNode *midNext = midPrev->next->next;

    midPrev->next = midNext;
    delete mid;

    ListNode *temp = head;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}