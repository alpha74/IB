// Store K parts of LL in a vector. Reverse the parts and recombine them.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *reverse( ListNode *A )
{
    ListNode *first, *second, *third ;
    first = NULL ;
    second = A ;
    third = second -> next ;
    
    while( second != NULL )
    {
        second -> next = first ;
        first = second ;
        second = third ;
        
        if( third != NULL )
            third = third -> next ;
    }
    
    return first ;
}
 
int get_length( ListNode* A )
{
    int len = 0 ;
    
    while( A != NULL )
    {
        len++ ;
        A = A -> next ;
    }
        
    return len ;
}
 
ListNode* Solution::reverseList(ListNode* A, int B) 
{
    // For size =0 and 1
    if( A == NULL || A -> next == NULL || B == 1 )
        return A ;
   
   // Size >= 2 
   
   // Divide and store the linked list
   vector<ListNode *> parts ;
   ListNode *first, *last ;
   
   first = A ;
   parts.push_back( first ) ;
  
   int len = get_length( A ) ;
   int diff = B ;
  
   len = len / B ;
   len-- ;
   while( len-- )
   {
      diff = B -1 ;
      
      while( diff-- )
      {
          
          first = first -> next ;
      }
      
      parts.push_back( first -> next ) ;
      ListNode *temp = first ;
      
      first = first -> next ;
      temp -> next = NULL ;
   }
   
   // Take each LL from vector, reverse it and store back.
   for( int i = 0 ; i < parts.size() ; i++ )
   {
       parts[i] = reverse( parts[i] ) ;
   }
   
   // Join all the parts
   first = parts[0] ;
   
   for( int i = 0 ; i < parts.size() -1 ; i++ )
   {
       last = parts[i] ;
       
       while( last -> next != NULL )
       {
           last = last -> next ;
       }
       
       // Join this last with first of next part
       if( i + 1 < parts.size() )
        last -> next = parts[i+1] ;
   }
   
   return first ; 
}
