// Sort both arrays. Take max of both array diff.

int Solution::mice(vector<int> &A, vector<int> &B) 
{
    sort( A.begin(), A.end() ) ;
    sort( B.begin(), B.end() ) ;
    
    int mtime = INT_MIN ;
    
    for( int i = 0 ; i < A.size() ; i++ )
    {
        int currtime = abs( A[i] - B[i] ) ;
        
        mtime = max( mtime, currtime ) ;
    }
    
    return mtime ;
}
