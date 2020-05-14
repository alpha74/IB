// Don't add all three numbers. 
// Use A[i] == -1 * ( A[j]+A[k]) to prevent overflow condition.
// Same logic as 3 Sum

#define ll long long int

vector<vector<int> > Solution::threeSum(vector<int> &A) 
{
	int size = A.size() ;
	int B = 0 ;
	
	vector< vector<int> > ret ;
	map< vector<int>, bool> uniq ;
	
	if( size < 3 )
		return ret ;		
		
	int i = 0, j = 0, k = 0 ;
	
	// Sort the array
	sort( A.begin(), A.end() ) ;
	
	for( i = 0 ; i < size-2 ; i++ )
	{
		j = i+1 ;
		k = size-1 ;
		
		while( j < k )
		{
		    int tsum = A[j] + A[k] ;
		    tsum = -1 * tsum ;
		    
			// Check for sum
			if( A[i] == tsum )
			{
			    
				vector<int> row ;
				
				row.push_back( A[i] ) ;
				row.push_back( A[j] ) ;
				row.push_back( A[k] ) ;
				
				sort( row.begin(), row.end() ) ;
				
				// Find if this triplet already exists
				auto iter = uniq.find( row ) ;
				
				if( iter == uniq.end() ) 
				{
					uniq.insert( pair< vector<int>, bool> ( row, false ) ) ;
					ret.push_back( row ) ;
				}
				j++ ;
			    k-- ;
			}		
			
			
			else if( A[i] > tsum )
				k-- ;
			else
				j++ ;

		}
	}
	
	return ret ;
}
