// https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

/*
Easy Pesy Lemon Squeezy

Problem :
Find the Kth node from the end of the linked list.

Approach :
1. Take two pointers, first and second and point them to the head of the linked list.
2. Move the second pointer to the Kth node from the start.
3. Now, move both the pointers one by one until the second pointer reaches the end of the linked list.

Edge cases :(Things to consider)

second reach end of the ll and cnt!=k , return -1 (Don't forget to check cnt not only second pointer)
*/

#include <bits/stdc++.h>
using namespace std;

int getKthFromLast(Node *head, int k)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL && cnt < k)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL && cnt != k) // edge case , dont foget cnt
    {
        return -1;
    }
    Node *temp1 = head;
    while (temp != NULL)
    {
        temp1 = temp1->next;
        temp = temp->next;
    }
    return temp1->data;
}