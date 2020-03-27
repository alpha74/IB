// Leave half nodes and point to next node.
// Store half nodes in stack, and start comparing from first element.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int Solution::lPalin(ListNode* A) 
{
    int size = 0, ret = 1 ;

    ListNode *temp = A, *first = A;
    
    // Get size of LL
    while( temp != NULL )
    {
        size = size + 1 ;
        temp = temp -> next ;
    }
    
    if( size > 1 )
    {
        int half = size / 2 ;
        
        int i = 0, j = 0 ;
        
        temp = A ;
        // Position the second pointer
        for( i = 1 ; i < (size/2) ; i++ )
        {
            temp = temp -> next ;
        }
        
        temp = temp -> next ;
        
        if( size % 2 != 0 )
        {
            temp = temp -> next ;
        }
        
        // Create stack to store half values
        stack<int> vals ;
        while( temp != NULL )
        {
            vals.push( temp -> val ) ;
            temp = temp -> next ;
        }
       
        // Check for equal values.
        while( ret == 1 && !vals.empty() )
        {
            if( first -> val != vals.top() )
                ret = 0 ;
            
            vals.pop() ;
            first = first -> next ;
        }
        
    }
    else
        ret = 1 ;
    
    return ret ;
}
