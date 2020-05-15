// Read all comments only sequentially.

vector<int> Solution::subUnsort(vector<int> &A) 
{
    int size = A.size() ;
    vector<int> ret ;
    
    int start = -1, end = -1 ;
    
    if( size < 2 )
    {
        ret.push_back( -1 ) ;
        return ret ;
    }
 
    
    bool stop = false ;
    // Start from start till order is broken
    for( int i = 0 ; i < size-1 && stop == false ; i++ )
    {
        if( A[i] > A[i+1] )
        {
            start = i ;
            stop = true ;
        }
    }
    
    stop = false ;
    // Start from end till order is broken
    for( int i = size-1 ; i > 0 && stop == false ; i-- )
    {
        if( A[i-1] > A[i] )
        {
            stop = true ;
            end = i ;
        }
    }
    
    // Check if array is already sorted
    if( start == -1 && end == -1 )
    {
        ret.push_back( -1 ) ;
        return ret ;
    }
    
    // Find min element in range: start, end
    int min = start ;
    int max = end ;
    
    for( int i = start ; i <= end ; i++ )
    {
        if( A[i] < A[min] )
            min = i ;
            
        if( A[i] > A[max] )
            max = i ;
    }
    
    // Find if any element is > A[min] in range 0,start-1
    int actual_start = -1 ;
    for( int i = 0 ; i < start && actual_start == -1 ; i++ )
    {
        if( A[i] > A[min] )
            actual_start = i ;
    }
    
    // Find if any element is < A[max] in range size-1, end+1
    int actual_end = -1 ;
    for( int i = size-1 ; i > end && actual_end == -1 ; i-- )
    {
        if( A[i] < A[max] )
            actual_end = i ;
    }
        
    // Check if new start and end are found
    if( actual_start != -1 )
        start = actual_start ;
    if( actual_end != -1 )
        end = actual_end ;
        
    // Set return
    ret.push_back( start ) ;
    ret.push_back( end ) ;
    
    return ret ;
}
