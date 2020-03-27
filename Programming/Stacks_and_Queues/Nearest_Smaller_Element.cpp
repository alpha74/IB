// Use stack to store current element. Pop till curr element is smaller than top.
// Update stack.

vector<int> Solution::prevSmaller(vector<int> &A) 
{
    stack<int> stk ;        
    vector<int> ret ;       // Return answer array
    int size = A.size() ;
    
    // Smallest is always -1.
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
            // Pop till top element is >= curr element
            while( stk.top() >= A[i] )
            {
                stk.pop() ;
            }
            
            // Set the smallest value from stack
            ret.push_back( stk.top() ) ;
            // Push curr element in stack
            stk.push( A[i] ) ;
        }
    }
    
    return ret ;
}
