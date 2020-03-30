/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *rev( ListNode *A )
{
    if( A == NULL || A -> next == NULL )
        return A ;
    
    ListNode *Anext = A -> next ;
    ListNode *head = rev( A -> next ) ;
    
    Anext -> next = A ;
    
    return head ;
}
 
ListNode* Solution::reverseList(ListNode* A) 
{
    ListNode *newA = rev( A ) ;
    A -> next = NULL ;
    
    return newA ;
}
