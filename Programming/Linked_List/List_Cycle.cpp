// Slow-Fast pointers method, and Floyd's cycle detection method.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// Returns if cycle exists
ListNode* cycleExists( ListNode *A )
{
    bool ret = false ;
    ListNode *cnode = NULL ;
    
    if( A -> next == A && A != NULL )
    {
        ret = true ;
        cnode = A ;
    }
    
    else if( A != NULL )
    {
        ListNode *slow = A -> next ;
        ListNode *fast = A -> next ;
     
        if( fast != NULL )
        {
            fast = fast -> next ;
        
            while( fast != NULL && ret == false )
            {
                if( slow == fast )
                {
                    ret = true ;
                    cnode = fast ;
                }
                    
                else
                {
                    slow = slow -> next ;
                    fast = fast -> next ;
                    
                    if( fast != NULL )
                        fast = fast -> next ;
                }
            }
        }
    }
    else
        ret = false ;
    
    if( ret == false )
        return NULL ;
    else
        return cnode ;
}
 
ListNode* Solution::detectCycle(ListNode* A) 
{
    // Check if cycle exists
    ListNode *cnode = cycleExists( A ) ;
    
    if( cnode == NULL )
        return NULL ;
    else
    {
        ListNode *node = A ;
        
        // Iterate till both pointers meet
        while( node != cnode )
        {
            node = node -> next ;
            cnode = cnode -> next ;
        }
        
        return node ;
    }
    
}
