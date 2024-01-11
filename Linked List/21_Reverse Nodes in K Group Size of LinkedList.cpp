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

std::pair<ListNode *, ListNode *> reverseNode(ListNode *start, ListNode *end)
{
    ListNode *temp = start;
    ListNode *prev = NULL;

    while (temp)
    {
        ListNode *res = temp->next;
        temp->next = prev;

        prev = temp;
        temp = res;

        if (prev == end)
            break;
    }

    return {prev, start};
}

int main()
{
    std::vector<int> num(6);
    std::iota(begin(num), end(num), 1);

    int key;
    std::cin >> key;

    ListNode *head = traverse(num);
    ListNode *temp = head;

    ListNode *start = head;
    std::pair<ListNode *, ListNode *> prev = {NULL, NULL};
    int count = 1;

    ListNode *newHead = NULL;

    while (temp)
    {
        if (count == key)
        {
            ListNode *res = temp->next;
            std::pair<ListNode *, ListNode *> inox = reverseNode(start, temp);

            if (newHead == NULL)
                newHead = inox.first;

            if (prev.first && prev.second)
                prev.second->next = inox.first;

            prev = inox;

            temp = res;
            start = temp;

            count = 1;
        }
        else
        {
            temp = temp->next;
            count++;
        }
    }

    if (start)
        prev.second->next = start;

    temp = newHead;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}