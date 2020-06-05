// https://www.interviewbit.com/problems/find-duplicate-in-array/

// Using Floyd's slow and fast pointers.

int Solution::repeatedNumber(const vector<int> &A) 
{
    int slow = A[0] ;       // slow = head
    int fast = A[ A[0] ] ;  // fast = slow -> next
    int ret = -1 ;
    
    while( slow != fast )
    {
        slow = A[ slow ] ;      // slow = slow -> next 
        fast = A[ A[fast] ] ;   // fast = fast -> next -> next 
    }
    
    slow = 0 ;
    
    // Finding the duplicate number
    while( slow != fast )
    {
        slow = A[ slow ] ;      // slow = slow -> next 
        fast = A[ fast ] ;      // fast = fast -> next 
    }

    if( slow == 0 )
        ret = -1 ;
    else
        ret = slow ;
  
    return ret ;
}
