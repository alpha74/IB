// Use Sliding window. Maintain best till now, keeping zerocount <= B.

vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int l = 0, r = 0 ;
    int size = A.size() ;
    int bestl = 0, bestsize = 0, zerocount = 0 ;
    vector<int> ret ;
    
    while( r < size )
    {
        if( zerocount <= B )
        {
            if( A[r] == 0 )
                zerocount++ ;
            r++ ;
        }
        
        if( zerocount > B )
        {
            if( A[l] == 0 )
                zerocount-- ;
            l++ ;
        }
        
        // Check for best window
        if( (r-l) > bestsize && zerocount <= B )
        {
            bestsize = (r-l) ;
            bestl = l ;
        }
    }
    
    // Fill the output array
    for( int i = bestl ; i < ( bestl + bestsize ) ; i++ )
    {
        ret.push_back( i ) ;
    }
    
    return ret ;
}
