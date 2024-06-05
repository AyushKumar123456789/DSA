// https://leetcode.com/problems/intersection-of-two-linked-lists/

/*
Correct Solution:
*/

/*
!! Very Important !! : Treat NULL as node because if we not let that pointer to go to null it lead to TLE
*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;
    while (ptr1 != ptr2)
    {
        if (ptr1 == NULL)
        {
            ptr1 = headB;
        }
        else
        {
            ptr1 = ptr1->next;
        }
        if (ptr2 == NULL)
        {
            ptr2 = headA;
        }
        else
        {
            ptr2 = ptr2->next;
        }
    }
    return ptr1;
}

/*
!!!!!!!!!!DONT USE THIS!!!!!!!!!!!!
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while (ptr1 != ptr2)
        {
            if (ptr1 == NULL)
            {
                ptr1 = headB;
            }
            if (ptr2 == NULL)
            {
                ptr2 = headA;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};