// https://leetcode.com/problems/middle-of-the-linked-list/

/*
For Even legth of LL:
    1->2->3->4->5->6
    Here, 4 is the middle element

If for Evne length of LL:
    1->2->3->4->5
    Here, 3 is the middle element

    Then, start fast with head->next;
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
};

ListNode *head = NULL;

void insert(int data)
{
    ListNode *newNode = new ListNode();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << (temp != NULL ? "->" : "->NULL");
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    insert(6);
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    printList(head);
    Solution obj;
    ListNode *middle = obj.middleNode(head);
    cout << middle->data << endl;

    return 0;
}