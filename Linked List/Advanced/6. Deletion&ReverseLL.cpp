#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

void deleteNode(struct Node **head, int key)
{
    Node *temp = *head;
    while (temp->data != key)
    {
        temp = temp->next;
    }
    Node *to_delet = temp->next;
    temp->data = temp->next->data;
    temp->next = temp->next->next;
    delete (to_delet);
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        return;
    }
    Node *curr = *head_ref;
    Node *prev = NULL;
    Node *nxt;
    do
    {
        nxt = curr->next;
        if (prev != NULL)
        {
            curr->next = prev;
        }
        prev = curr;
        curr = nxt;
    } while (curr != *head_ref);
    curr->next = prev;
    *head_ref = prev;
}

void push(int data)
{
    Node *ptr1 = new Node();
    Node *temp = head;
    ptr1->data = data;
    ptr1->next = head;

    if (head != NULL)
    {
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    head = ptr1;
}

void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    /* Initialize lists as empty */
    int i;
    for (i = 5; i > 0; i--)
    {
        push(i);
    }

    cout << "List Before Deletion: ";
    printList(head);

    deleteNode(&head, 3);

    cout << "\nList After Deletion: ";
    printList(head);

    reverse(&head);

    cout << "\nList After Reversing: ";
    printList(head);

    return 0;
}