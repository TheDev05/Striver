#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int temp)
    {
        this->val = temp;
        this->next = NULL;
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
        pointer = temp;
    }

    return head;
}

Node *deleteNode(Node *temp, Node *prevNode)
{
    Node *nextNode = NULL;
    Node *result = NULL;

    if (temp->next != NULL)
        nextNode = temp->next;

    if (prevNode && nextNode)
    {
        prevNode->next = nextNode;
        result = NULL;
    }
    else if (prevNode)
    {
        prevNode->next = NULL;
        result = NULL;
    }
    else if (nextNode)
    {
        temp->next = NULL;
        result = nextNode;
    }

    delete temp;
    return result;
}

int main()
{
    int key;
    std::cin >> key;

    std::vector<int> num(5);
    std::iota(begin(num), end(num), 1);

    Node *head = traverse(num);
    Node *temp = head, *prev = NULL;

    int index = 0;
    while (temp)
    {
        if (index++ == key)
        {
            Node *res = deleteNode(temp, prev);
            if (res)
                head = res;

            break;
        }

        prev = temp;
        temp = temp->next;
    }
}