// https://leetcode.com/problems/merge-k-sorted-lists/description/

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

/*
Time Complexity: O(Nlogk) where k is the number of linked lists.
The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. But finding the node with the smallest value just costs O(1) time.

*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr){} * ListNode(int x, ListNode *next) : val(x), next(next){} *
};

class comp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    int k = lists.size();
    for (int i = 0; i < k; i++)
    {
        if (lists[i] != NULL)
        {
            pq.push(lists[i]);
        }
    }
    ListNode *dummy = new ListNode;
    ListNode *tail = dummy;
    while (!pq.empty())
    {
        ListNode *temp = pq.top();
        tail->next = temp;
        tail = temp;
        pq.pop();
        if (temp->next != NULL)
            pq.push(temp->next);
    }
    return dummy->next;
}