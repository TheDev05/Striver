#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
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
        pointer = temp;
    }

    return head;
}

ListNode *getNode(int len1, int len2, ListNode *head1, ListNode *head2)
{
    ListNode *temp1 = head1, *temp2 = head2;

    int delta = len1 - len2;
    ListNode *res = NULL;

    while (temp1 && temp2)
    {
        if (delta == 0)
        {
            if (temp1 == temp2)
            {
                res = temp1;
                break;
            }

            temp2 = temp2->next;
        }
        else
            delta--;

        temp1 = temp1->next;
    }

    return res;
}

int main()
{
    // O(n+m)

    std::vector<int> num1 = {1, 2, 3, 4, 5, 6};
    std::vector<int> num2 = {13, 14, 5, 6};

    ListNode *head1 = traverse(num1);
    ListNode *head2 = traverse(num2);

    ListNode *temp1 = head1, *temp2 = head2;
    int len1 = 0, len2 = 0, count = 1;

    while (1)
    {
        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;

        if (temp1 == NULL && len1 == 0)
            len1 = count;
        if (temp2 == NULL && len2 == 0)
            len2 = count;

        if (temp1 == NULL && temp2 == NULL)
            break;

        count++;
    }

    if (len1 > len2)
        getNode(len1, len2, head1, head2);
    else
        getNode(len2, len1, head2, head1);
}