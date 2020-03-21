// Creates two new lists of less and great.
// Deletes old list and returns head of less.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) 
{
    ListNode *less, *great ;
    ListNode *templ, *tempg ;
    
    less = new ListNode( 0 ) ;
    great = new ListNode( 0 ) ;
    
    templ = less ;
    tempg = great ;
    
    while( A != NULL )
    {
        ListNode *newnode = new ListNode( A -> val ) ;
        
        if( A -> val < B )
        {
            less -> next = newnode ;
            less = less -> next ;
        }
        else
        {
            great -> next = newnode ;
            great = great -> next ;
        }
        
        ListNode *del ;
        A = A -> next ;
        delete del ;
    }
    
    less -> next = tempg -> next ;
    great -> next = NULL ;
    
    less = templ -> next ;
    
    delete templ ;
    delete tempg ;
    
    return less ;
}
