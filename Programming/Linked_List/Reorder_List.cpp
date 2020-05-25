// Get second half of list.
// Reverse the second half.
// Start from first list, and reorder nodes taking one each from second reversed half.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* A) 
{
    // 0 nodes
    if( A == NULL ) 
        return A ;
    
    // 1 node
    else if( A -> next == NULL )
        return A ;

    // 2 or more nodes
    else
    {
        ListNode *first, *second, *third ;
        
        first = NULL ;
        second = A ;
        third = second -> next ;
        
        while( second != NULL )
        {
            second -> next = first ;
            
            first = second ;
            second = third;
            
            if( third != NULL )
                third = third -> next ;
        }
        
        return first ;
    }
} 
 
ListNode* Solution::reorderList(ListNode* A) 
{
	if( A == NULL )
		return A ;
		
	else if( A -> next == NULL )
		return A ;
		
	else if( A -> next -> next == NULL )
		return A ;
		
	else
	{
		// Get the mid element
				
		ListNode *slow, *fast ;
		ListNode *slowprev = NULL ;
		slow = A ;
		fast = A ;
		
		while( fast != NULL )
		{
			fast = fast -> next ;
			slowprev = slow ;
			slow = slow -> next ;
			
			if( fast != NULL )
				fast = fast -> next ;
		}
		
		// Make first half of list independent
		slowprev -> next = NULL ;
				
		// Reverse the second half of list. slow points to head of second reversed half
		slow = reverseList( slow ) ;
		
		// Start with fisrt element of first half list and reorder one element from second list
		fast = A ;	// Using fast as a temp pointer
		
		// 1 2 3
		// 5 4
		
		while( fast != NULL && slow != NULL )
		{
			// Store next pointers
			ListNode *fastnext = fast -> next ;
			ListNode *slownext = slow -> next ;
			
			// Reorder the pointers
			fast -> next = slow ;
			slow -> next = fastnext ;
			
			// Iterate the fast and slow pointers
			fast = fastnext ;
			slow = slownext ;
		}
		
		return A ;
	}			
}
