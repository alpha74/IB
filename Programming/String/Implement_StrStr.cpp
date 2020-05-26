// Match first index of B against every index of A
// If match is found, check for whole B comparison.

int Solution::strStr(const string A, const string B) 
{
	if( A.length() == 0 || B.length() == 0 )
		return -1 ;
		
	else if( B.length() > A.length() )
		return -1 ;
		
	else
	{
		int index = -1 ;
		bool found = false ;
		
		for( int i = 0 ; i < A.size() && found == false ; i++ )
		{
			// Check if first char of B matches with current char in A
			if( A[i] == B[0] )
			{
				int tempindex = i ;
				bool match = true ;
				
				for( int j = i, n = 0 ; n < B.size() && match == true ; n++, j++ )
				{
					if( A[j] != B[n] )
						match = false ;
				}
				
				
				if( match == true )
				{
					index = tempindex ;
					found = true ;
				}
			}
			
		}	
		return index ;
	}

}
