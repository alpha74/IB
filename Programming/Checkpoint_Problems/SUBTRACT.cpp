// Store last half of list in stack. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) 
{
    stack<int> val ;
    int size = 0 ;
    ListNode *temp = A ;
    
    // Calculate the size of linked list
    while( temp != NULL )
    {
        size++ ;
        temp = temp -> next ;
    }
    
    if( size > 1 )
    {
        int half = size/2 ;
        
        temp = A ;
        // Iterate till half
        while( half-- )
        {
            temp = temp -> next ;
        }
        
        if( size % 2 != 0 )
            temp = temp -> next ;
        
        // Store last half
        while( temp != NULL )
        {
            val.push( temp -> val ) ;
            temp = temp -> next ;
        }
        
        temp = A ;
        // Modify the LL elements
        while( !val.empty() )
        {
            temp -> val = val.top() - temp -> val ;
            temp = temp -> next ;
            val.pop() ;
        }
        
        return A ;
    }
    else
        return A ;
}
