// Take head of ecah list and add the numbers. Take care of carry remaining after consuming of both lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    ListNode *ret, *head ;
    
    head = new ListNode(0) ;
    ret = head ;
    
    int carry = 0 ;
    
    while( A != NULL && B != NULL )
    {
        int sum = A -> val + B -> val + carry ;
        carry = 0 ;
        
        if( sum > 9 )
        {
            carry = 1 ;
            sum = sum - 10 ;
        }
        
        ListNode *newnode = new ListNode( sum ) ;
        head -> next = newnode ;
        head = head -> next ;
        
        A = A -> next ;
        B = B -> next ;
    }
    
    if( B != NULL )
    {
        while( B != NULL ) 
        {
            int sum = B -> val + carry ;
            carry = 0 ;
            
             if( sum > 9 )
            {
                carry = 1 ;
                sum = sum - 10 ;
            }
            
            ListNode *newnode = new ListNode( sum ) ;
            head -> next = newnode ;
            head = head -> next ;
            
            B = B -> next ;
        }
    }
    else
    {
        while( A != NULL )
        {
            int sum = A -> val + carry ;
            carry = 0 ;
            
            if( sum > 9 )
            {
                carry = 1 ;
                sum = sum - 10 ;
            }
            
            ListNode *newnode = new ListNode( sum ) ;
            head -> next = newnode ;
            head = head -> next ;
            
            A = A -> next ;
        }
    }
    
    if( carry > 0 )
    {
        ListNode *newnode = new ListNode( carry ) ;
        head -> next = newnode ;
        head = head -> next ;
    }
    
    head -> next = NULL ;
    head = ret ;
    ret = ret -> next ;
    
    delete head ;
    
    
    return ret ;
}
