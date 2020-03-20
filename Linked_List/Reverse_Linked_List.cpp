// Three pointer approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) 
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
