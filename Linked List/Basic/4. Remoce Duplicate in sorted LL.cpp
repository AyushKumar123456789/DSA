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

/*
Remoce Duplicate in LL
*/

Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
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
    insert(7);
    insert(7);
    insert(7);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    cout << "LL : ";
    print();
    head = removeDuplicates(head);
    cout << "Removing Duplicate : " << endl;
    print();

    return 0;
}
