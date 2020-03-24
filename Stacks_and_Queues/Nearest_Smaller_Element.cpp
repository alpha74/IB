// Use stack to store current element. Pop till curr element is smaller than top.

vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int> stk ;
    vector<int> ret ;
    int size = A.size() ;
    
    stk.push( -1 ) ;
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
