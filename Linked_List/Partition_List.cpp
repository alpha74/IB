// Two pointer approach.

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
    ListNode *less, *great, *tempA = A ;
    ListNode *Fless, *Fgreat ;
    
    less = NULL ;
    great = NULL ;
    
    while( A != NULL )
    {
        int val = A -> val ;
        
        if( val < B )
        {
            if( less == NULL )
            {
                less = A ;
                Fless = less ;
            }
            else
            {
                less -> next = A ;
                less = less -> next ;
            }
        }
        else
        {
            if( great == NULL )
            {
                great = A ;
                Fgreat = great ;
            }
            else
            {
                great -> next = A ;
                great = great -> next ;
            }
        }
        
        A = A -> next ;
    }
    
    if( less != NULL && great != NULL )
    {
        less -> next = Fgreat ;
        great -> next = NULL ;
    }
    else if( less == NULL )
    {
        Fless = Fgreat ;
    }
    else
    {
        less -> next = NULL ;
    }
    
    return Fless ;
}
