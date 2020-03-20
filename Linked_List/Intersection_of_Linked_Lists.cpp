// Get diff in length of both lists.
// Iterate diff times on longer list.
// Now, iterate on both lists at a time, and check for sameness of nodes.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) 
{
    // If one of the list is NULL
    if( A == NULL || B == NULL )
        return NULL ;
        
    else
    {
        int countA = 0, countB = 0, diff = 0 ;
        
        ListNode *pa = A, *pb = B, *ret = NULL ;
        
        // Count elements in A
        while( pa != NULL )
        {
            countA++ ;
            pa = pa -> next ;
        }
        // Count elements in B
        while( pb != NULL )
        {
            countB++ ;
            pb = pb -> next ;
        }
        
        diff = countA - countB ;
        pa = A ;
        pb = B ;
        
        // If A has more elements
        if( diff >= 0 )
        {
            while( diff-- )
            {
                pa = pa -> next ;
            }
        }
        // If B has more elements
        else
        {
            diff = -1 * diff ;
            
            while( diff-- )
            {
                pb = pb -> next ;
            }
        }
        
        // Iterate both pointers at same time, and check for sameness
        while( pa != NULL && pb != NULL && ret == NULL )
        {
            if( pa == pb )
                ret = pa ;
            
            pa = pa -> next ;
            pb = pb -> next ;
        }
        
        return ret ;
    }
}
