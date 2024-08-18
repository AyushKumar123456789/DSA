// https://www.geeksforgeeks.org/problems/sort-a-linked-list/1

/*
Author :
Bhaskar
IIT DHANBAD (CSE'25)
*/

#include <bits/stdc++.h>
using namespace std;

Node *findMid(Node *head)
{
    Node *s = head;
    Node *f = head->next;

    while (f and f->next)
    {
        s = s->next;
        f = f->next->next;
    }

    return s;
}

Node *merge(Node *l, Node *r)
{

    Node *ans = new Node(-1);
    Node *t = ans;

    Node *l1 = l;
    Node *l2 = r;
    while (l1 and l2)
    {
        if (l1->data <= l2->data)
        {
            t->next = new Node(l1->data);
            t = t->next;
            Node *k = l1;
            l1 = l1->next;
            delete (k);
        }
        else
        {
            t->next = new Node(l2->data);
            t = t->next;
            Node *k = l2;
            l2 = l2->next;
            delete (k);
        }
    }

    while (l1)
    {
        t->next = new Node(l1->data);
        t = t->next;
        Node *k = l1;
        l1 = l1->next;
        delete (k);
    }
    while (l2)
    {

        t->next = new Node(l2->data);
        t = t->next;
        Node *k = l2;
        l2 = l2->next;
        delete (k);
    }

    Node *k = ans->next;
    delete (ans);
    return k;
}

Node *mergeSort(Node *head)
{
    // your code here

    if (!head or !head->next)
        return head;

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}