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

    ListNode *head1 = traverse(num);
    ListNode *head2 = traverse(num);

    std::multiset<std::pair<int, ListNode *>> inox;

    inox.insert({head1->val, head1});
    inox.insert({head2->val, head2});

    ListNode *prev = NULL, *newHead = NULL;
    while (inox.size())
    {
        auto it = inox.begin();
        ListNode *temp = it->second;
        int val = it->first;

        inox.erase(it);

        if (prev)
            prev->next = temp;
        prev = temp;

        if (newHead == NULL)
            newHead = prev;

        if (temp->next)
            inox.insert({temp->next->val, temp->next});
    }

    ListNode *temp = newHead;
    while (temp)
        std::cout << temp->val << " ",
        temp = temp->next;
}