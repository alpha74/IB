vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int> stk ;
    vector<int> ret ;
    int size = A.size() ;
    
    // Smallest is alway -1.
    stk.push( -1 ) ;
    // For first element: always -1.
    ret.push_back( -1 ) ;
    stk.push( A[0] ) ;
    
    for( int i = 1 ; i < size ; i++ )
    {
        if( stk.top() < A[i] )
        {
            ret.push_back( stk.top() ) ;
            stk.push( A[i] ) ;
        }
        else
        {
            while( stk.top() >= A[i] )
            {
                stk.pop() ;
            }
            
            ret.push_back( stk.top() ) ;
            stk.push( A[i] ) ;
        }
    }
    
    return ret ;
}
