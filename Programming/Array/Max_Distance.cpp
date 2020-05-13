// Store array element and its index as a pair in array.
// Sort it
// Traverse it from last. Update max distance and maxj

int Solution::maximumGap(const vector<int> &A) 
{
    int size = A.size() ;
    
    if( size <= 1 )
        return 0 ;
    
    vector< pair<int,int> > index ;
    
    // Make vector of array element and its index
    for( int i = 0 ; i < size ; i++ )
    {
    	index.push_back( make_pair( A[i],i ) ) ;
	}
    
    // Sort the pair array
    sort( index.begin(), index.end() ) ;
    
    int maxdiff = 0 ;
    int maxj = index[ size - 1 ].second ;
    
    // Traverse the sorted array and get max
    for( int i = size-2 ; i >= 0 ; i-- )
    {
    	// Get max diff
    	maxdiff = max( maxdiff, maxj - index[i].second ) ;
    	
    	// Update max j
    	maxj = max( maxj, index[i].second ) ;
	}
    
    return maxdiff ;
}
