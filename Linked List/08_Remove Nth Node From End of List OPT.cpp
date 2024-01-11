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
    std::vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int index;
    std::cin >> index;

    ListNode *head = traverse(num);
    ListNode *prev = NULL, *next = NULL;

    ListNode *first = head, *last = head;
    int firstIndex = 1, lastIndex = 1;

    // Concept of Sliding Window

    while (last)
    {
        if (lastIndex - firstIndex == index)
        {
            if (last->next == NULL)
            {
                prev = first;
                break;
            }

            last = last->next;
            first = first->next;

            lastIndex++;
            firstIndex++;
        }
        else
            lastIndex++,
                last = last->next;
    }

    if (prev == NULL)
        return head->next;

    if (prev->next && prev->next->next)
        next = prev->next->next;

    if (prev && next || prev)
        prev->next = next;

    ListNode *temp = head;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}