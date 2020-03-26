// Use first, second and third pointers.
// Use a prev poitner to point to swapped node again.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) 
{
    if( A == NULL )
        return A ;
    else if( A -> next == NULL )
        return A ;
    else
    {
        ListNode *first, *second, *third, *prev = NULL ;
        ListNode *head = A -> next ;
        
        first = A ;
        second = first -> next ;
        
        while( second != NULL )
        {
            third = second -> next ;
            second -> next = first ;
            first -> next = third ;

            if( prev != NULL )
            {
                prev -> next = second ;
            }
            prev = first ;

            first = third ;
            
            if( first == NULL )
                second = NULL ;
            else
                second = first -> next ;
        }
        
        return head ;
    }
}
