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
    std::vector<int> num1(3);
    // std::iota(begin(num1), end(num1), 1);

    std::vector<int> num2(3);
    // std::iota(begin(num2), end(num2), 4);

    num1[0] = num1[1] = num1[2] = 9;
    num2[0] = num2[1] = num2[2] = 9;

    ListNode *LL1 = traverse(num1);
    ListNode *LL2 = traverse(num2);

    ListNode *temp1 = LL1;
    ListNode *temp2 = LL2;

    ListNode *head = NULL;
    ListNode *pointer = head;

    int carry = 0;
    while (temp1 || temp2)
    {
        int val1 = 0, val2 = 0;
        if (temp1)
            val1 = temp1->val,
            temp1 = temp1->next;
        if (temp2)
            val2 = temp2->val,
            temp2 = temp2->next;

        int sum = val1 + val2 + carry;
        int newValue = sum % 10;
        carry = sum / 10;

        ListNode *temp = new ListNode(newValue);
        if (head == NULL)
            head = temp;
        else
            pointer->next = temp;

        pointer = temp;
    }

    while (carry)
    {
        int res = carry % 10;

        ListNode *temp = new ListNode(res);
        pointer->next = temp;
        pointer = temp;

        carry = carry / 10;
    }

    ListNode *temp = head;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}