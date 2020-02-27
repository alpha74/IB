// Count bits using AND with 1 at that index

int Solution::numSetBits(unsigned int A) 
{
	int count = 0 ;
	
	for( int i = 0 ; i < 32 ; i++ )
	{
		if( A & ( 1 << i ) )
			count++ ;
	}
	
	return count ;
}
