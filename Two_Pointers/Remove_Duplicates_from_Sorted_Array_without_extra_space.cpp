// Without using extra space. Comparing with largest element to stop loop.

int get_larger( vector<int>&A, int v, int i )
{
    int ret = -1 ;
    
    // Find first element larger than v starting from index i
    for( ; i < A.size() ; i++ )
    {
        if( A[ i ] > v )
        {
            ret = i ;
            i = A.size() ;
        }
    }
    
    return ret ;
}

int Solution::removeDuplicates(vector<int> &A) 
{
    int size = A.size() ;
    int ret = 1 ;
    int largest = A[size-1] ;
    
    // If array has 0 or 1 elements
    if( size == 0 || size == 1 )
        ret = size ;
    
    else
    {
        int i = 0 ;
        for( i = 1 ; i < size ; i++ )
        {
            if( A[i-1] == largest )
            {
                break ;
            }
            
            int larger_index = get_larger( A, A[i-1], i ) ;
            
            if( larger_index != -1 )
            {
                A[i] = A[ larger_index ] ;
                
                if( A[i] == largest )
                {
                    i++ ;
                    break ;
                }
            }
        }
        
        ret = i ;
    }
    
    return ret ;
}
