#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next, *prev;

    Node(int temp)
    {
        this->val = temp;
        this->next = this->prev = nullptr;
    }
};

Node *traverse(std::vector<int> &num)
{
    Node *head = new Node(num[0]);
    Node *pointer = head;

    for (int i = 1; i < num.size(); i++)
    {
        Node *temp = new Node(num[i]);

        pointer->next = temp;
        temp->prev = pointer;

        pointer = temp;
    }

    return head;
}

int main()
{
    std::vector<int> num1(5);
    std::vector<int> num2(5);

    std::iota(begin(num1), end(num1), 1);
    std::iota(begin(num2), end(num2), 1);

    Node *head1 = traverse(num1);
    Node *head2 = traverse(num2);

    Node *temp1 = head1, *temp2 = head2;
    Node *newHead = NULL, *prev = NULL;

    while (temp1 && temp2)
    {
        if (temp1->val < temp2->val)
        {
            if (prev)
                prev->next = temp1;

            prev = temp1;
            temp1 = temp1->next;
        }
        else
        {
            if (prev)
                prev->next = temp2;
            prev = temp2;

            if (newHead == NULL)
                newHead = prev;

            if (temp1->val == temp2->val)
            {
                Node *res = temp2->next;

                prev->next = temp1;
                prev = temp1;

                temp1 = temp1->next;
                temp2 = res;
            }
            else
                temp2 = temp2->next;
        }

        if (newHead == NULL)
            newHead = prev;
    }

    while (newHead)
    {
        std::cout << newHead->val << " ";
        newHead = newHead->next;
        /* code */
    }
}