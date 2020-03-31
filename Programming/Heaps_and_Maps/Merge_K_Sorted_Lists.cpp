// Take 2 lists at a time and merge. 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *mergeSorted( ListNode *A, ListNode *B )
{
    if( A == NULL )
        return B ;
    else if( B == NULL )
        return A ;
        
    else
    {
        ListNode *pa, *pb, *head, *temp ;
        
        pa = A ;
        pb = B ;
        
        // Check for initial number
        if( pa -> val < pb -> val )
        {
            head = pa ;
            pa = pa -> next ;
        }
        else
        {
            head = pb ;
            pb = pb -> next ;
        }
        
        temp = head ;
        
        while( pa != NULL && pb != NULL )
        {
            if( pa -> val < pb -> val )
            {
                head -> next = pa ;
                pa = pa -> next ;
                head = head -> next ;
            }
            else
            {
                head -> next = pb ;
                pb = pb -> next ;
                head = head -> next ;
            }
        }
        
        if( pa != NULL )
            head -> next = pa ;
        else
            head -> next = pb ;
        
        // Return temp storing first node
        return temp ;
    }
        
}
 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    int size = A.size() ;
    
    if( size > 1 )
    {
        ListNode *list1, *list2 ;
        list1 = A[0] ;
        list2 = A[1] ;
        
        for( int i = 1 ; i < size ; i++ )
        {
            list2 = A[i] ;
            list1 = mergeSorted( list1, list2 ) ;
        }
        
        return list1 ;
    }
    else
        return A[0] ;
}
