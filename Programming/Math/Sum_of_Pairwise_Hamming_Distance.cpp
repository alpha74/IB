// Counting number of set and unset bits at bits : 0-31
// Use exp:  for each bit index: sumi = (count)*(arr.size()-count)*2

#define ll long long int
#define MOD 1000000007

int Solution::hammingDistance(const vector<int> &A)
{
	ll sum = 0 ;
	int size = A.size() ;
	
	// Traverse from 0 to 31th bit
	for( int i = 0 ; i < 32 ; i++ )
	{
		ll setcount = 0 ;
		
		// Count number of set bits
		for( int j = 0 ; j < size ; j++ )
		{
			// If current bit is set
			if( A[j] & ( 1 << i ) )
			{
				setcount++ ;
			}
		}
		
		// Add this total sum
		sum = sum + ( setcount * ( size-setcount ) * 2 ) % MOD ;
		
	}
	
	
	return sum % MOD ;
}
