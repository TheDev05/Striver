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
            return NULL;

        if (fast == slow)
        {
            // means loop exits

            slow = head;
            while (slow != fast)
            {
                // now move from head and from meet point
                slow = slow->next;
                fast = fast->next;
            }

            // loop start node
            return slow;
        }
    }

    // if exited means no cycle, fast end at null
    std::cout << "No Cycle";
}