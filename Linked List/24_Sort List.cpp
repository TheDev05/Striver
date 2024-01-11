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

ListNode *getMid(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast)
    {
        if (fast == NULL || fast->next == NULL || fast->next->next == NULL)
            return slow;

        if (fast->next)
            fast = fast->next->next;
        slow = slow->next;
    }

    return NULL;
}

ListNode *mergeThem(ListNode *left, ListNode *right)
{
    ListNode *a = left, *b = right;
    ListNode *newHead = new ListNode(0);
    ListNode *pointer = newHead;

    while (a && b)
    {
        if (a->val < b->val)
        {
            pointer->next = a;
            pointer = a;
            a = a->next;
        }
        else
        {
            pointer->next = b;
            pointer = b;
            b = b->next;
        }
    }

    pointer->next = a ? a : b ? b
                              : NULL;

    return newHead->next;
}

ListNode *sortThem(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *mid = getMid(head);

    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;

    left = sortThem(left);
    right = sortThem(right);

    return mergeThem(left, right);
}

int main()
{
    std::vector<int> num = {4, 4};
    // std::vector<int> num = {4, 19, 14, 5, -3, 1, 8, 9};
    // std::iota(begin(num), end(num), 1);

    ListNode *head = traverse(num);
    ListNode *temp = head;

    temp = sortThem(head);

    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}