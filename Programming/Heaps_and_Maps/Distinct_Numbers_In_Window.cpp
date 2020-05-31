// Use a map to store uniq elements. 
// See comments for approach.

vector<int> Solution::dNums(vector<int> &A, int B)
{
  // To store elements and frequency
	map<int,int> uniq ;
  // Result vector
	vector<int> ret ; 
	
	// Do for first B numbers
	for( int i = 0 ; i < B ; i++ )	
	{
		auto iter = uniq.find( A[i] ) ;
		
		// If entry not exists, create and set frequency to 1
		if( iter == uniq.end() )
			uniq.insert( pair<int,int>( A[i], 1 )) ;
			
		// Else increment frequency	
		else
			iter -> second +=1 ;
	}
	// Add first window entry
	ret.push_back( uniq.size() ) ;
	
	// Start from Bth element
	for( int i = 1 ; i + B - 1 < A.size() ; i++ )
	{
		// Decrement entry of (i-1)th element, as it falls out of window
		auto iter = uniq.find( A[i-1] ) ;
		iter -> second -= 1 ;
		
		// Remove it if frequency is 0
		if( iter -> second == 0 )
			uniq.erase( iter ) ;
		
		// Find (i+B-1)th element in map, as it is the newest element in window
		int newi = i+B-1 ;
		
		iter = uniq.find( A[ newi ] ) ;
		
		// If entry exists, increment, else create new entry
		if( iter == uniq.end() ) 
			uniq.insert( pair<int,int>( A[ newi ], 1 )) ;
		else
			iter -> second +=1 ;
			
			
		//  Insert size of uniq elements in window
		ret.push_back( uniq.size() ) ;
	}
	
	return ret ;
}
