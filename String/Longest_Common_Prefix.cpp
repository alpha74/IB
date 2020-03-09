// Looping each string for size boundation; and matching characters.

string Solution::longestCommonPrefix(vector<string> &A) 
{
	int i = 0 ;
	string ret = "" ;
	
	bool stop = false ;
	
	while( stop == false )
	{
		// Check for each string if the i is less than their size
		for( int j = 0 ; j < A.size() ; j++ )
		{
			if( i >= A[ j ].length() )
			{
				j = A.size() ;	// break 
				stop = true ;
			}
		}
		
		// Check for each string: char at pos i
		if( stop == false )
		{
			char c = A[0][i] ;
			bool same = true ;
			for( int j = 0 ; j < A.size() ; j++ )
			{
				if( c != A[j][i] )
				{
					j = A.size() ;	// break
					same = false ;
				}
			}	
			
			if( same == true )
			{
				ret += A[0][ i ] ;
			}
		}
		i++ ;
		
	}
	
	return ret ;
}
