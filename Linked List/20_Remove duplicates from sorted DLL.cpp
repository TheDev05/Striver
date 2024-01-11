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
    std::vector<int> num = {1, 1, 1, 2};
    // std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *temp = head;

    while (temp)
    {
        if (temp->prev && temp->prev->val == temp->val)
        {
            Node *res = temp->next;
            if (temp->next)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            else
                temp->prev->next = NULL;

            delete temp;
            temp = res;
        }
        else
            temp = temp->next;
    }

    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
}