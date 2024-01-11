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

int addThem(Node *temp)
{
    if (temp->next == NULL)
    {
        int sum = temp->val + 1;
        temp->val = sum % 10;
        return sum / 10;
    }

    int carry = addThem(temp->next);
    int sum = temp->val + carry;

    temp->val = sum % 10;
    return sum / 10;
}

int main()
{
    std::vector<int> num = {9, 9, 9, 9};
    // std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *temp = head;

    int value = addThem(temp);

    if (value)
    {
        Node *newHead = new Node(value);
        newHead->next = head;
        head = newHead;
    }

    Node *inox = head;
    while (inox)
    {
        std::cout << inox->val << " ";
        inox = inox->next;
    }
}
