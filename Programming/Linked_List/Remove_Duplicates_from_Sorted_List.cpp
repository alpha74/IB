// Check for curr and next element val. Iterate to next only when next is not equal to curr.
// Take care when node is NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    if( A == NULL )
        return A ;
    
    else if( A -> next == NULL )    
        return A ;
        
    else
    {
        ListNode *temp = A;
        ListNode *del ;
        
        while( A != NULL )
        {
            if( ( A -> next != NULL ) && A -> val == ( A -> next -> val ))
            {
                del = A -> next ;
                
                A -> next = del -> next ;
                
                delete del ;
            }
            else
                A = A -> next ;
        }
        
        return temp ;
    }
    
}
