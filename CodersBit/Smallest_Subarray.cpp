// Traverse the array from start and add sum of elements.
// In nested loop, try to reduce the size of sub-array from left side(starting).

int Solution::solve(vector<int> &A, int B) 
{
    int min = INT_MAX;
    long int sum = A[0] ;
    
    int start = 0 ;
    
    // If any one element is >= K
    if( sum >= B )
    {
        min = 1 ;
        return 1 ;
    }
    
    // Traverse all the elements
    for( int i = 1 ; i < A.size() ; i++ )
    {
        sum += A[ i ] ;
        
        // Shorten the sub-array from left side(start)
        while( sum >= B && start <= i )
        {
            if( (i - start ) +1 < min )
                min = ( i - start) + 1 ; 
            
            // Remove the remove element's sum    
            sum -= A[start];
            
            start++ ;
        }
        
    }
    // If no possible sub-array exists
    if( min == INT_MAX )
        return -1;
    else
        return min ;
}
