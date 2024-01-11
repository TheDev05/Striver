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

    std::map<int, ListNode *> data;
    ListNode *head = traverse(num);
    ListNode *temp = head;

    int count = 1;
    while (temp)
    {
        data[count] = temp;

        temp = temp->next;
        count++;
    }

    int size = count - 1;
    ListNode *prev = data[size - index];
    ListNode *next = NULL;

    if (prev->next->next)
        next = prev->next->next;

    prev->next = next;

    temp = head;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}