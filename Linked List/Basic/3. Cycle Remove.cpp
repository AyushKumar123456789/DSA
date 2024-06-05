// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

void removeLoop(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (fast != NULL && fast->next != NULL) // loop exist
    {
        slow = head;
        if (fast == slow)
        { // both meet at head
            while (slow->next != fast)
            {
                slow = slow->next;
            }
            slow->next = NULL;
        }
        else
        {
            while (fast->next != slow->next)
            {
                fast = fast->next;
                slow = slow->next;
            }
            fast->next = NULL;
        }
    }
}