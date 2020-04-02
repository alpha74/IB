// Use three pointers to move from left to right.
// Think on the iterating condition.

int get_max( int a, int b, int c )
{
    return max( a, max( b, c ) ) ;
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) 
{
    int a = 0, b = 0, c = 0 ;
    int sizeA = A.size(), sizeB = B.size(), sizeC = C.size() ;
    bool stop = false ;
    int ret = INT_MAX ;
    
    while( ( a < sizeA || b < sizeB || c < sizeC ) && stop == false )
    {
        // Get max of difference
        int maxval = get_max(abs( A[a] - B[b] ),abs( B[b] - C[c] ),abs(C[c] - A[a]) ) ;
        
        ret = min( ret, maxval ) ;
        
        int nexta = INT_MAX, nextb = INT_MAX, nextc = INT_MAX ;
        
        // Moving pointers : Go one step ahead and calc max value
        if( a+1 < sizeA )
            nexta = get_max( abs(A[a+1]-B[b]), abs(B[b]-C[c]), abs(C[c]-A[a+1]) ) ;
            
        if( b+1 < sizeB )
            nextb = get_max( abs(A[a]-B[b+1]), abs( B[b+1]-C[c]), abs(C[c]- A[a]) ) ;
            
        if( c+1 < sizeC )
            nextc = get_max( abs(A[a]-B[b]), abs( B[b]-C[c+1]), abs(C[c+1]- A[a]) ) ;
        
        // Get the smallest of three values
        int minmax = min( nexta, min( nextb, nextc )) ;
        
        // If no min was found
        if( minmax == INT_MAX )
            stop = true ;
        else if( minmax == nexta )
            a++ ;
        else if( minmax == nextb )
            b++ ;
        else
            c++ ;
            
    }
    
    return ret ;
}
