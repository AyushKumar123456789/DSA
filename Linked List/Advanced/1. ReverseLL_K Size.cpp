#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

/*
Reversing LL of K size using vector
*/

Node *reverseK(int k)
{
    if (head == NULL)
    {
        return head;
    }
    vector<int> temp;
    Node *ptr = head;
    while (ptr != NULL)
    {
        temp.push_back(ptr->data);
        ptr = ptr->next;
    }

    for (int i = 0; i < temp.size(); i += k)
    {
        if (i + k < temp.size())
        {
            reverse(temp.begin() + i, temp.begin() + i + k);
        }
        else
        {
            reverse(temp.begin() + i, temp.end());
        }
    }

    ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        ptr->data = temp[i];
        i++;
        ptr = ptr->next;
    }
    return head;
}

/*
reverse LL of K size using recursion
*/

Node *reverseK(Node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    int idx = 0;

    while (current != NULL && idx < k)
    {
        idx++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = reverseK(current, k);
    return prev;
}

/*
Reversing LL of K size iteratively
*/

Node *reverse_k_Ierative(Node *head, int k)
{

    Node *current = head;
    Node *prevTail = NULL;
    Node *newHead = NULL;

    while (current != NULL)
    {
        Node *prev = NULL;
        Node *next = NULL;
        Node *segmentHead = current;

        // Reverse k nodes
        int idx = 0;
        while (current != NULL && idx < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            idx++;
        }

        // If newHead is not set, set it to the head of the new reversed list
        if (newHead == NULL)
        {
            newHead = prev;
        }

        // Connect the previous part with the current
        if (prevTail != NULL)
        {
            prevTail->next = prev;
        }

        // Move prevTail to the end of the reversed segment
        prevTail = segmentHead;
    }

    return newHead;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    insert(8);
    insert(7);
    insert(6);
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);

    cout << "Original LL: ";
    print();
    cout << endl;

    head = reverse_k_Ierative(head, 3);

    cout << "Reversed LL: ";
    print();
    cout << endl;

    return 0;
}