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
    std::vector<int> num = {3, 3, 3, 1, 1, 1, 2, 2, 2};

    Node *head = traverse(num);

    Node *one = NULL, *two = NULL, *three = NULL;
    Node *pointerOne = one, *pointerTwo = two, *pointerThree = three;

    Node *temp = head;
    while (temp)
    {
        if (temp->val == 1)
        {
            if (one == NULL)
                one = temp;
            else
                pointerOne->next = temp;

            pointerOne = temp;
        }
        else if (temp->val == 2)
        {
            if (two == NULL)
                two = temp;
            else
                pointerTwo->next = temp;

            pointerTwo = temp;
        }
        else if (temp->val == 3)
        {
            if (three == NULL)
                three = temp;
            else
                pointerThree->next = temp;

            pointerThree = temp;
        }

        temp = temp->next;
    }

    pointerThree->next = NULL;
    pointerTwo->next = three;
    pointerOne->next = two;

    temp = one;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}