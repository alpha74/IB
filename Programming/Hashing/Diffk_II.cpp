// Use hashing.
// Use this: If A[i]-B is present OR A[i]+B is present, return 1.

int Solution::diffPossible(const vector<int> &A, int B) 
{
	  unordered_set<int> num ;
    int size = A.size() ;
    
    for( int i = 0 ; i < size ; i++ )
    {
        // If A[i]-B is present OR A[i]+B is present
        if( num.find( A[i]-B ) != num.end() || num.find( A[i]+B ) != num.end() )
            return 1 ;
        
        num.insert(A[i]);
    }
    return 0;
}
