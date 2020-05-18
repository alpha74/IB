// First understand the approach when B =1 
// Then, understand the other case.
// Follow comments

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
	if( A == NULL )
		return A ;
	
  // Case when B = 1
	if( B == 1 )
	{
		int count = 1 ;
		
		ListNode *first = NULL ;
		ListNode *second = A  ;
		ListNode *third = NULL ;
		
		if( second != NULL  )
			third = second -> next ;
		
		// The current first node	
		ListNode *secondtemp = second ;
			
		while( count <= C && second != NULL )
		{
			second -> next = first ;		
			
			first = second ;
			second = third ;
			
			if( third != NULL )
				third = third -> next ;
				
			count++ ;	
		}	
		
		secondtemp -> next = second ;
    
    // New head is returned here.
		return first ;
	}
	
	else
	{
		int count = 1 ;
		
		ListNode *tempA = A ;
		while( count < B-1 )
		{
			A = A -> next ;
			count++ ;
		}
		
    // Same as B = 1 from now
    
		ListNode *first = NULL ;
		ListNode *second = A -> next ;
		ListNode *third = NULL ;
		
		if( second != NULL  )
			third = second -> next ;
		
		// The current first node	
		ListNode *secondtemp = second ;
			
		while( count < C && second != NULL )
		{
			second -> next = first ;		
			
			first = second ;
			second = third ;
			
			if( third != NULL )
				third = third -> next ;
				
			count++ ;	
		}	
		
    // Different here, pointers point to different nodes as compared to above and original A is returned.
		secondtemp -> next = second ;
		A -> next = first ;
    
		return tempA ;
	}
}
