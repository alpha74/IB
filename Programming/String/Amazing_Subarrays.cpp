// Counting number of subarrays


bool isvowel( char c )
{
	
	bool ret = false ;
	
	switch( c )
	{
		case 'a' :
		case 'e' :
		case 'i' :
		case 'o' :
		case 'u' :
			
		case 'A' :
		case 'E' :
		case 'I' :
		case 'O' :
		case 'U' : ret = true ; break ;
		
		default: ret = false ;
		
	}
	
	return ret ;
}

int Solution::solve(string A) 
{
	int i = 0, j = 0, n = A.length() ;
	
	int count = 0 ;
	
	for( int i = 0 ; i < n ; i++ )
	{
		if( isvowel( A[i] ) )
			count += ( n - i ) ;
	}
	
	return count % 10003 ;
}
