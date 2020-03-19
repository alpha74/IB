// Simple O(n^2) approach

vector<int> Solution::nextGreater(vector<int> &A) 
{
    vector<int> ret ;
    bool found = false ;
    int size = A.size() ;
    
    if( size < 2 )
    {
        ret.push_back( -1 ) ;
        return ret;
    }
    
    for( int i = 0 ; i < size ; i++ )
    {
        found = false ;
        
        for( int j = i+1 ; j < size && found == false ; j++ )
        {
            if( A[j] > A[i] )
            {
                ret.push_back( A[j] ) ;
                found = true ;
            }
        }
        
        if( found == false )
            ret.push_back( -1 ) ;
    }
    
    return ret ;
}
