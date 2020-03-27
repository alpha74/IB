// Iterate till (size-B) and keep reversing; and connect apprpriate node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    long long int size = 0 ;
    
    // Count number of nodes
    ListNode *temp, *last, *first ;
    temp = A ;
    
    while( temp != NULL )
    {
        size++ ;
        
        // Get the last node
        if( temp -> next == NULL )
            last = temp ;
        
        temp = temp -> next ;
    }

    if( size > 1 )
    {
    	B = B % size ;
    	int rot = size - B ;
    	
    	if( rot > 0 && B != 0 )
    	{
    		rot-- ;
    		last -> next = A ;
			
		temp = A ;

		while( rot-- )
		{
			temp = temp -> next ;
		}

		first = temp -> next ;
		temp -> next = NULL ;
		}
		else
			first = A ;     	
	}
	else
		first = A ;
    
    return first ;
}
