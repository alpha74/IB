// Simple approach with O(1) extra space.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if( A == NULL && B == NULL )
        return NULL ;
    
    else if( A == NULL )
        return B ;
    
    else if( B == NULL )
        return A ;
    
    else
    {
        ListNode *head = new ListNode(0) ;
        ListNode *temp ;
        temp = head ;
        
        while( A != NULL && B != NULL  )
        {
            if( A -> val < B -> val )
            {
                head -> next = A ;
                head = head -> next ;
                A = A -> next ;
            }
            else
            {
                head -> next = B ;
                head = head -> next ;
                B = B -> next ;
            }
        }
        
        while( A != NULL )
        {
            head -> next = A ;
            head = head -> next ;
            A = A -> next ;
        }
        
        while( B != NULL )
        {
            head -> next = B ;
            head = head -> next ;
            B = B -> next ;
        }
        
        head = temp -> next ;
        delete temp ;
        
        return head ;
    }
    
}
