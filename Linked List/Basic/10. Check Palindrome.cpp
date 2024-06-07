// https://leetcode.com/problems/palindrome-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return 1;
        }
        ListNode *fast = head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if (fast == NULL)
        {
            fast = curr;
            curr = prev;
        }
        else
        {
            fast = curr->next;
            curr = prev;
        }
        while (fast != NULL)
        {
            if (fast->val != curr->val)
            {
                return 0;
            }
            fast = fast->next;
            curr = curr->next;
        }
        return 1;
    }
};