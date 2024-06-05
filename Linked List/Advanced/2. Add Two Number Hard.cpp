// https://leetcode.com/problems/add-two-numbers-ii/

/*
Approach   1 : Reverse the linked list and then add the two numbers

Time complexity : O(n+m)
Space complexity : O(n+m)

*/

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
    struct ListNode *reverse(struct ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1)
        {
            l1 = reverse(l1);
        }
        if (l2)
        {
            l2 = reverse(l2);
        }
        int carry = 0;
        ListNode *head = NULL;
        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1)
            {
                sum += (l1->val);
                l1 = l1->next;
            }
            if (l2)
            {
                sum += (l2->val);
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *temp = new ListNode(sum % 10);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};