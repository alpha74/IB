// Maintain two arrays: max product till now, AND min product till now.

int Solution::maxProduct(const vector<int> &A) 
{
    int size = A.size() ;
    
    // Maintain two arrays
    // Max product till now
    vector<int> maxarray( size ) ;
    // Min product till now
    vector<int> minarray( size ) ;
    
    maxarray[0] = A[0] ;
    minarray[0] = A[0] ;
    
    // Result var
    int ret = A[0] ;
    
    for( int i = 1 ; i < size ; i++ )
    {
        if( A[i]  > 0 )
        {
            maxarray[i] = max( A[i], A[i] * maxarray[i-1] ) ;
            minarray[i] = min( A[i], A[i] * minarray[i-1] ) ;
        }
        else
        {
            maxarray[i] = max( A[i], A[i] * minarray[i-1] ) ;
            minarray[i] = min( A[i], A[i] * maxarray[i-1] ) ;
        }
        
        ret = max( ret, maxarray[i] ) ;
    }
    
    return ret ;
}
