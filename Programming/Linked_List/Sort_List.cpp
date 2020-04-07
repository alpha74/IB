// Implement Merge Sort

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Merge two sorted Lists
ListNode *merge( ListNode *A, ListNode *B )
{
    ListNode *head = new ListNode(0) ;
    ListNode *temp = head ;
    
    while( A != NULL && B != NULL )
    {
        if( A -> val < B -> val )
        {
            head -> next = A ;
            A = A -> next ;
            head = head -> next ;
        }
        else
        {
            head -> next = B ;
            B = B -> next ;
            head = head -> next ;
        }
    }
    
    if( A != NULL )
    {
        head -> next = A ;
    }
    else
    {
       head -> next = B ; 
    }
    
    head = temp ;
    head = head -> next ;
    
    delete temp ;
    
    return head ;
}
 
// Partition a List
ListNode* partition( ListNode *A )
{ 
    if( A -> next == NULL )
        return A ;
    else
    {
       ListNode *a, *b ;       // Partitons
       a = A ;
       b = A ;
       
       // Find mid pointer
       while( b != NULL )
       {
            b = b -> next ;
           
            if( b != NULL && b -> next != NULL )
            {
            	b = b -> next ;
            	a = a -> next ;
			}
     }
       
    	b = a -> next ;
    	a -> next = NULL ;
    	a = A ;
        
        // Recursive call to partition more
        a = partition( a ) ;
        b = partition( b ) ;
        
        // Sort merge
        a = merge( a, b ) ;
        
        return a ;
    }
}
 
ListNode* Solution::sortList(ListNode* A)
{
    return partition( A ) ;
}

