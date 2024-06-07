// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*

Approach 1 : Counting Sort (Using Count Array)
1. Traverse the linked list and count the number of 0s, 1s, and 2s.
2. Traverse the linked list again and update the data of each node according to the count of 0s, 1s, and 2s.
3. Time Complexity: O(N), where N is the number of nodes in the linked list AND Space Complexity: O(1).

Approach 2 : Three Pointers (Using Three Pointers)
1. Initialize three pointers zero, one, and two to NULL.
2. Traverse the linked list and update the next pointer of each node to NULL.
3. Traverse the linked list again and update the next pointer of each node according to the value of the node.
4. Time Complexity: O(N), where N is the number of nodes in the linked list AND Space Complexity: O(1).


*/

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

Node *sortList(Node *head)
{
    int count[3] = {0, 0, 0};
    Node *ptr = head;
    while (ptr != NULL)
    {
        count[ptr->data]++;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (count[i] == 0)
            i++;
        else
        {
            ptr->data = i;
            count[i]--;
            ptr = ptr->next;
        }
    }
    return head;
}

/*
Three Pointers (Using Three Pointers)
Time Complexity: O(N), where N is the number of nodes in the linked list
Space Complexity: O(1)

*/

Node *sortList(Node *head)
{
    Node *zero = new Node(0);
    Node *one = new Node(0);
    Node *two = new Node(0);
    Node *zero_ptr = zero, *one_ptr = one, *two_ptr = two;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            zero_ptr->next = curr;
            zero_ptr = zero_ptr->next;
        }
        else if (curr->data == 1)
        {
            one_ptr->next = curr;
            one_ptr = one_ptr->next;
        }
        else
        {
            two_ptr->next = curr;
            two_ptr = two_ptr->next;
        }
        curr = curr->next;
    }
    zero_ptr->next = (one->next) ? one->next : two->next;
    one_ptr->next = two->next;
    two_ptr->next = NULL;
    head = zero->next;
    delete zero, one, two;
    return head;
}

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << (curr->next ? " -> " : " ->NULL ");
        curr = curr->next;
    }
}

void insert(Node **head, int data)
{
    Node *temp = new Node(data);
    temp->next = *head;
    *head = temp;
}

int main()
{
    Node *head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 0);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 0);

    cout << "Original List: ";
    printList(head);
    cout << endl;

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);
    cout << endl;

    return 0;
}