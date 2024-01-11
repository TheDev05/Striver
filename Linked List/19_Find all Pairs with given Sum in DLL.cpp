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

Node *findLast(Node *head)
{
    Node *temp = head;
    Node *slow = head, *fast = head;

    while (slow && fast)
    {
        if (fast->next == NULL)
            return fast;
        if (fast->next && fast->next->next == NULL)
            return fast->next;

        slow = slow->next;
        if (fast->next)
            fast = fast->next->next;
    }

    return NULL;
}

int main()
{
    std::vector<int> num = {1, 10};
    // std::iota(begin(num), end(num), 1);

    int key;
    std::cin >> key;

    Node *head = traverse(num);
    Node *temp = head;

    std::vector<std::pair<int, int>> inox;
    Node *first = head, *last = findLast(temp);

    while (first != last)
    {
        int delta = key - first->val;
        if (last->val == delta)
            inox.push_back({first->val, last->val}),
                first = first->next;
        else if (last->val > delta)
            last = last->prev;
        else
            first = first->next;
    }

    for (auto [first, second] : inox)
        std::cout << first << " " << second << '\n';
}