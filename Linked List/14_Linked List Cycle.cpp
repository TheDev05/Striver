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
        this->next = this->prev = NULL;
    }
};

Node *traverse(std::vector<int> &num)
{
    Node *head = new Node(num[0]);
    Node *pointer = head;

    for (int i = 1; i < num.size(); i++)
    {
        Node *temp = new Node(num[i]);

        temp->prev = pointer;
        pointer->next = temp;

        pointer = temp;
    }

    return head;
}

int main()
{
    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *fast = head, *slow = head;

    while (fast && slow)
    {
        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
        else
            break; /*means there is no loop*/

        if (fast == slow)
        {
            std::cout << "LOOP EXITS\n";
            break;
        }
    }

    std::cout << "LOOP NOT EXIST";
}