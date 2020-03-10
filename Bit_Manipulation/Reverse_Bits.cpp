// Use two pointers and check for set bit.

unsigned int Solution::reverse(unsigned int A) 
{
	int BITS = 32 ;
	int i = 0, j = 31 ;
	
	
	unsigned int ret = 0, num = 0 ;
	
	for( i = 0 ; i < BITS ; i++ )
	{
		num = ( 1 << i ) ;
		
		if( A & num )
		{
			ret = ret | ( 1 << j ) ;
		}
		
		j--  ;
	}
	
	return ret ;
}
