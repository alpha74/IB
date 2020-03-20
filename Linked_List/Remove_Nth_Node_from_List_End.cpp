// Find number of nodes, and iterate till (len-B) and delete the next node.
// Handle deletion of first node separately.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    int len = 0, diff = 0;
    
    ListNode *head = A, *del ;
    
    // Count number of nodes
    while( head != NULL )
    {
        len++ ;
        head = head -> next ;
    }
    
    diff = len - B - 1 ;
    
    // If node other than first is to be deleted
    if( diff >= 0 )
    {
        // Iterate to node previous to node to be removed
        head = A ;
        while( diff-- )
        {
            head = head -> next ;
        }
        
        // Get node to be deleted
        del = head -> next ;
        head -> next = del -> next ;
        
        delete del ;
        
        return A ;
    }   
    // If first node is to be deleted
    else
    {
        del = A ;
        head = A -> next ;
        
        delete del ;
        
        return head ;
    }
}
