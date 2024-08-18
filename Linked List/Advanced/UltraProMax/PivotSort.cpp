#include <bits/stdc++.h>
using namespace std;

/*
Author :
Bhaskar
IIT DHANBAD (CSE'25)
*/

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *pivotSort(Node *head, int x)
{
    Node *less = new Node(-1);
    Node *more = new Node(-1);
    Node *equal = new Node(-1);

    Node *l = less;
    Node *m = more;
    Node *e = equal;

    Node *curr = head;

    while (curr)
    {
        if (curr->data < x)
        {
            l->next = curr;
            l = l->next;
        }
        else if (curr->data == x)
        {
            e->next = curr;
            e = e->next;
        }
        else
        {
            m->next = curr;
            m = m->next;
        }
        curr = curr->next;
    }

    l->next = (equal->next) ? equal->next : more->next;
    e->next = more->next;
    m->next = NULL;

    return less->next;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    int x = 3;

    head = pivotSort(head, x);

    printList(head);

    return 0;
}