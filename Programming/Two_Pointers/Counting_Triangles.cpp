// O(n2)
// Sort the array.
// Fix one index, and use two pointer approach on other tow indices.

#define MOD 1000000007
#define ll long long int

int Solution::nTriang(vector<int> &A) 
{
	ll size = A.size() ;
	
	// If size is < 3, no triangle can be formed
	if( size < 3 )
		return 0 ;
	
  sort( A.begin(), A.end() ) ;
	ll count = 0 ;
	
	for( int k = size-1 ; k > 1 ; k-- )
	{
		ll i = 0, j = k - 1 ;
		
		while( i < j )
		{
			// Triangle can be formed keeping A[k], A[i] and in range (j-i), if true
			if( A[i] + A[j] > A[k] )
			{
				count += ( j - i ) ;
				count = count % MOD ;
				j-- ;
			}
			else
			{
				i++ ;
			}
			
		}
	}
	
	return count ;
}
