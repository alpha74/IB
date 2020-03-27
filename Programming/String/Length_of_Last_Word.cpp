// Iterate from last till spaces are encountered.

int Solution::lengthOfLastWord(const string A) 
{
	int n = A.length() ;
	
	int count = 0 ;
	
	int i = n-1 ;
	
	while( A[i] == ' ' )
	{
		i-- ;
	}
	
	for( ; i >= 0 ; i-- )
	{
		if( A[i] == ' ' )
		{
			i = -1 ;
		}
		else
			count++ ;
	}
	
	return count ;
}
