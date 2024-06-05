// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

#include <bits/stdc++.h>
using namespace std;

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

Node *head1 = NULL;
Node *head2 = NULL;

Node *insert(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << (curr->next != NULL ? "->" : "->NULL");
        curr = curr->next;
    }
    cout << endl;
}

/*
Find the intersection of two sorted linked lists.
Time Complexity: O(N+M)
Space Complexity: O(max(N,M))
Space Complexity can be reduced to O(1) by removing the extra linked list and making one of the linked list as the resultant linked list.
*/

Node *findIntersection(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *Head = NULL;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            Node *temp = new Node(head1->data);
            if (Head == NULL)
            {
                Head = temp;
                head = temp;
            }
            else
            {
                head->next = temp;
                head = temp;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return Head;
}

/*
Approach 2: With O(1) Space Complexity
*/

Node *findIntersection_reduced_space(Node *head1, Node *head2)
{
    Node *head = head1;
    Node *Head = head1;
    Node *prev = NULL;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
        else
        {
            prev = head;
            head->data = (head1->data);
            head = head->next;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    if (prev != NULL)
        prev->next = NULL;
    else
        Head = NULL;
    return Head;
}

int main()
{
    head1 = insert(head1, 6);
    head1 = insert(head1, 5);
    head1 = insert(head1, 4);
    head1 = insert(head1, 3);
    head1 = insert(head1, 2);
    head1 = insert(head1, 1);
    head2 = insert(head2, 8);
    head2 = insert(head2, 6);
    head2 = insert(head2, 4);
    head2 = insert(head2, 2);
    print(head1);
    print(head2);
    Node *head = findIntersection(head1, head2);
    print(head);
    head = findIntersection_reduced_space(head1, head2);
    cout << "Reduced Space Complexity: ";
    print(head);
    return 0;
}