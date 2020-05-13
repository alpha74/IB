// Use total sum for changing pointer positions
// Use abs() in maxdiff. See code.

#define ll long long int

int Solution::threeSumClosest(vector<int> &A, int B) 
{
	int size = A.size() ;
	
	if( size < 3 )
		return 0 ;
	else if( size == 3 )
		return A[0] + A[1] + A[2] ;
		
		
	int i = 0, j = 0, k = 0 ;
	
	// Sort the array
	sort( A.begin(), A.end() ) ;
	
	// Min sum, and maxdiff between B and triple sum
	ll minsum = 0 ;
	ll maxdiff = INT_MAX ;
	
	bool stop = false ;
	
	for( i = 0 ; i < size-2 && stop == false ; i++ )
	{
		j = i+1 ;
		k = size-1 ;
		
		while( j < k && stop == false )
		{
			if( j != i && k != i )
			{
				ll allsum = A[i] + A[j] + A[k] ;
				
				// Get diff between triple sum and B
				if( abs( B - allsum ) < maxdiff )
				{
					maxdiff = abs( B - allsum ) ;
					minsum = allsum ;
				}				
				
				// Pointer controller		
				if( allsum == B )
					stop = true ;
				else if( allsum > B )
					k-- ;
				else
					j++ ;
			}
			else
			{
				if( j == i )
					j++ ;
				else
					k-- ;
			}
		}
	}
	
	return minsum ;
}
