// Store duplicate elements in array.
// Traverse the LL and check if it exists in the array, then remove it.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void print( ListNode* list )
{
    cout << "\n List : " ;
    
    while( list != NULL )
    {
        cout << list -> val ;
        list = list -> next ;
    }
}

void print( vector<int> l )
{
    cout << "\n Array: " ;
    
    for( int i = 0 ; i < l.size() ; i++ )
        cout << " " << l[i] ;
}
 
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    //cout << "\n Call " ;
    
    if( A == NULL )
        return A ;
    else if( A -> next == NULL )
        return A ;
        
    //cout << "\n In" ;    
        
    vector<int> dup ;
    
    // Store duplicates in array
    ListNode *temp = A ;
    ListNode *last = A ;
    temp = temp -> next ;
    
    while( temp != NULL )
    {
        if( temp -> val == last -> val )
        {
            if( dup.size() == 0 )
                dup.push_back( temp -> val ) ;
            else
            {
                if( dup.size() > 0 && dup[ dup.size() -1 ] != temp -> val )
                    dup.push_back( temp -> val ) ;
            }
        }
        
        last = temp ;
        temp = temp -> next ;
    }
    
    //print( dup ) ;
    
    if( dup.size() > 0 )
    {
        temp = A ;
        int i = 0 ;
        ListNode *head = new ListNode(0) ;
        head -> next = temp ;
        
        temp = head ;
        
        while( temp -> next != NULL )
        {
            if( temp -> next -> val == dup[i] ) 
            {
                ListNode *del = temp -> next ;
                
                temp -> next = del -> next ;
                delete del ;
            }
            else if( (i+1) < dup.size() && temp -> next -> val == dup[i+1] ) 
            {
            	i++ ;
                ListNode *del = temp -> next ;
                
                temp -> next = del -> next ;
                delete del ;
            }
            else 
            	temp = temp -> next ;
        }
        
        
        temp = head ;
        head = head -> next ;
        delete temp ;
    
        //print( head ) ;
    
        return head ;
    }
    
    //print( A ) ;
    
    return A ;
}
