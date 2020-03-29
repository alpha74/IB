// Create new node and append it in old list.
// Set random pointers and detach new list.

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
RandomListNode* Solution::copyRandomList(RandomListNode* A) 
{
    if( A == NULL )
        return NULL ;
  
    RandomListNode *newhead = NULL ;
    
    RandomListNode *tempA, *temp ;
    tempA = A ;
    
    // Create new list and insert it in original list after same node
    while( A != NULL )
    {
        RandomListNode *newnode = new RandomListNode( A -> label ) ;
        
        newnode -> next = A -> next ;
        A -> next = newnode ;
        
        A = A -> next -> next ;
    }
    
    // Traverse the list and set the random pointers 
    A = tempA ;
    
    while( A != NULL )
    {
        if( A-> random != NULL )
            A -> next -> random = A -> random -> next  ;
        
        A = A -> next -> next ;
    }
    
    // Separate the new list
    A = tempA ;
    while( A != NULL )
    {
        if( newhead == NULL )
        {
            newhead = A -> next ;
            temp = newhead ;
        }
        else
        {
            newhead -> next = A -> next ;
            newhead = newhead -> next ;
        }
        
        A -> next = A -> next -> next ;
        
        A = A -> next ;
    }
    
    newhead = temp ;
    
    return newhead ;
}
