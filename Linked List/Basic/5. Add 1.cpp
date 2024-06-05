// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include <bits/stdc++.h>
using namespace std;

int add(Node *head)
{
    if (head->next == NULL)
    {
        head->data++;
    }
    else
    {
        head->data += add(head->next);
    }
    int carry = head->data / 10;
    head->data %= 10;
    return carry;
}

Node *addOne(Node *head)
{
    if (head == NULL)
        return head;
    int carry = add(head);
    if (carry == 0)
    {
        return head;
    }
    else
    {
        Node *temp = new Node(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}