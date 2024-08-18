#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node *root, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = root;
    temp->prev = NULL;
    if (root != NULL)
        root->prev = temp;
    root = temp;
}

void printList(Node *node)
{
    Node *last;
    cout << "Traversal in forward Direction: ";
    while (node != NULL)
    {
        cout << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << endl;
    cout << "Traversal in reverse direction: ";
    while (last != NULL)
    {
        cout << last->data << " ";
        last = last->prev;
    }
}

void rotate(Node *head, int data)
{
    if (data == 0)
        return;
    Node *current = head;
    int count = 1;
    while (count < data && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;
    Node *kthNode = current;
    while (current->next != NULL)
        current = current->next;
    current->next = head;
    head->prev = current;
    head = kthNode->next;
    head->prev = NULL;
    kthNode->next = NULL;
    printList(head);
}
// Time Complexity: O(n)
// Space Complexity: O(1)

// Original linked list: Traversal in forward Direction: 10 20 30 40 50 60
// Traversal in reverse direction: 60 50 40 30 20 10