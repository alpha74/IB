// Sort and check min xor value for adjacent pairs.

int Solution::findMinXor(vector<int> &A) 
{
	int minxor = INT_MAX ;
	
	sort( A.begin(), A.end() ) ;
	
	for( int i = 1 ; i < A.size() ; i++ )
	{
		int x = A[i] ^ A[i-1] ;
		
		if( x < minxor )
			minxor = x ;
	}
	
	return minxor ;
}
