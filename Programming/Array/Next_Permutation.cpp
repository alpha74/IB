// https://www.interviewbit.com/problems/next-permutation/

// Read comments in code sequentially from func nextPermutation()

// Returns index of min element
int find_min( vector<int>&A, int i, int j, int n )
{
	int m = i ;
	
	for( ; i <= j ; i++ )
	{
		if( A[i] < A[m] && A[i] > n )
			m = i ;
	}
	return m ;
}

vector<int> Solution::nextPermutation(vector<int> &A)
{
	int size = A.size() ;
	
  // If size is 1
	if( size == 1 ) 
		return A ;
	
  // Else
	else
	{
		bool dec = true ;
		// Check for total descreasing order
		for( int i = 1 ; i < size && dec == true ; i++ )
		{
			if( A[i-1] <= A[i] )
				dec = false ;	
		}
		
		// Return sorted array if all decreasing
		if( dec == true )
		{
			sort( A.begin(), A.end() ) ;
			return A ;
		}
		else
		{
			// Find next permutation 
      
			int temp = 0 ;
			int decindex = -1 ;
			
			// Find first index from last where array is not increasing.
			for( int i = size-1 ; i > 0 && decindex == -1 ; i-- )
			{
				if( A[i] > A[i-1] )
					decindex = i-1 ; 
			}
			
			// Find minimum element just greater than element at decindex from range decindex+1 till last
			int minindex = find_min( A, decindex+1, size-1, A[decindex] ) ;
			
			// Swap values at decindex and minindex
			temp = A[ decindex ] ;
			A[ decindex ] = A[ minindex ] ;
			A[ minindex ] = temp ;
			
			// Sort the array from decindex+1 to size
			sort( A.begin() + decindex+1, A.end() ) ;
			
			// Return result
			return A ;
		}	
	}
	
}


