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

void reverse()
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

/*
Reversing the linked list using recursion
*/
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    cout << "Original Linked List: ";
    print();
    cout << endl;
    reverse();
    cout << "Reversed Linked List: ";
    print();
    cout << endl;
    head = reverse(head);
    cout << "Reversed Linked List using recursion: ";
    print();

    return 0;
}
