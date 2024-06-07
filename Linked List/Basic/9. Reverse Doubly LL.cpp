// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

/*
Rever the doubly linked list
*/
Node *reverseDLL(Node *head)
{
    Node *temp = head;
    while (head != NULL)
    {
        Node *x = head->prev;
        head->prev = head->next;
        head->next = x;
        temp = head;
        head = head->prev;
    }
    return temp;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << (curr->next ? " <-> " : " <->NULL ");
        curr = curr->next;
    }
}

void insert(Node **head, int data)
{
    Node *temp = new Node(data);
    temp->next = *head;
    if (*head != NULL)
        (*head)->prev = temp;
    *head = temp;
}

int main()
{
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    cout << "Original DLL: ";
    printList(head);
    head = reverseDLL(head);
    cout << "\nReversed DLL: ";
    printList(head);
    return 0;
}