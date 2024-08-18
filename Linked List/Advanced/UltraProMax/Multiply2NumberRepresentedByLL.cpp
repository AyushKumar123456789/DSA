// https://www.geeksforgeeks.org/problems/multiply-two-linked-lists/1

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

Node *rev(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *nxt = NULL;
    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

long long multiplyTwoLists(Node *first, Node *sec)
{
    // code here
    long long n1 = 0;
    long long n2 = 0;
    long long m = 1e9 + 7;
    Node *t1 = first;
    Node *t2 = sec;

    while (t1)
    {
        n1 = (n1 * 10 + t1->data) % m;
        t1 = t1->next;
    }
    while (t2)
    {
        n2 = (n2 * 10 + t2->data) % m;
        t2 = t2->next;
    }

    long long ans = ((n1 % m) * (n2 % m)) % m;

    return ans;
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    head1->next->next->next->next->next = new Node(6);
    head1->next->next->next->next->next->next = new Node(7);
    head1->next->next->next->next->next->next->next = new Node(8);
    head1->next->next->next->next->next->next->next->next = new Node(9);
    head1->next->next->next->next->next->next->next->next->next = new Node(10);

    Node *head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(5);
    head2->next->next->next->next->next = new Node(6);
    head2->next->next->next->next->next->next = new Node(7);
    head2->next->next->next->next->next->next->next = new Node(8);
    head2->next->next->next->next->next->next->next->next = new Node(9);
    head2->next->next->next->next->next->next->next->next->next = new Node(10);

    cout << multiplyTwoLists(head1, head2) << endl;

    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)
