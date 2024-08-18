// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given a link list, modify the list such that all the even numbers appear before all the odd numbers in the modified list.

Doable in first attemt , but little thinking needed.

If you want to remember sometihing, remember this How many variable you needed.

    Node *curr_even = NULL;
    Node *curr = head;
    Node *prev_even = NULL;
    Node *head_odd = NULL;

*/

class Node
{
public:
    int data;
    Node *next;
};

Node *divide(Node *head)
{
    Node *curr_even = NULL;
    Node *curr = head;
    Node *prev_even = NULL;
    Node *head_odd = NULL;

    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            if (curr_even == NULL)
            {
                curr_even = curr;
                head = curr;
            }
            else
            {
                curr_even->next = curr;
                curr_even = curr_even->next;
            }
            if (prev_even != NULL)
            {
                prev_even->next = curr->next;
            }
        }
        else
        {
            if (head_odd == NULL)
            {
                head_odd = curr;
            }
            prev_even = curr;
        }
        curr = curr->next;
    }
    curr_even->next = head_odd;
    return head;
}

void printList(Node *head)
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
    Node *head = new Node();
    head->data = 17;
    head->next = new Node();
    head->next->data = 15;
    head->next->next = new Node();
    head->next->next->data = 8;
    head->next->next->next = new Node();
    head->next->next->next->data = 12;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 10;
    head->next->next->next->next->next = new Node();
    head->next->next->next->next->next->data = 5;
    head->next->next->next->next->next->next = new Node();
    head->next->next->next->next->next->next->data = 4;
    head->next->next->next->next->next->next->next = new Node();
    head->next->next->next->next->next->next->next->data = 1;
    head->next->next->next->next->next->next->next->next = NULL;

    cout << "Original List : ";
    printList(head);
    cout << endl;

    head = divide(head);

    cout << "Modified List : ";
    printList(head);
    cout << endl;

    return 0;
}