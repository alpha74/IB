// Sort, Remove Duplicates and Find max sequence.

int Solution::longestConsecutive(const vector<int> &A) 
{
    vector<int> Ac, B ;
    int size = A.size() ;
    
    if( size == 0 )
        return 0 ;
    else if( size == 1 )
        return 1 ;
    else ;
    
    // Copy the array
    for( int i = 0 ; i < size ; i++ )
    {
        B.push_back( A[i] ) ;
    }
    
    // Sort the array
    sort( B.begin(), B.end() ) ;
    
    // Remove duplicates
    int last = B[0] ;
    Ac.push_back( B[0] ) ;
    
    for( int i = 1 ; i < size ; i++ )
    {
        if( B[i] != last )
        {
            Ac.push_back( B[i] ) ;
            last = B[i] ;
        }
    }
    
    B.clear() ;
    int len = 1 ;
    int maxlen = 1  ;
    
    // Find max len
    for( int i = 1 ; i < size ; i++ )
    {
        if( Ac[i] - Ac[i-1] == 1 )
        {
            len++ ;
            
            if( len > maxlen )
                maxlen = len ;
        }
        else
        {
            len = 1 ;
        }
    }
    
    return maxlen ;
}
