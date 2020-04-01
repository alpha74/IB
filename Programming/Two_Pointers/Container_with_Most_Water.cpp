// Use two pointers starting from left and right, and keep track of max-area.
// Check moving conditions for both pointers.

int Solution::maxArea(vector<int> &A) 
{
    int size = A.size() ;
    
    // Boundary condition
    if( size < 2 )
        return 0 ;
    
    int maxarea = -1 ;
    
    int i = 0, j = size - 1 ;
    
    while( i < j )
    {
        int area = 0 ;
        area = min(A[i], A[j] ) * ( j - i ) ;
        
        if( area > maxarea )
            maxarea = area ;
        
        if( A[i] < A[j] )
            i++ ;
        else
            j-- ;
        
    }
    return maxarea ;
}
