// Count set bits at each pos. Mod with 3(thrice occurence here. Can be modified for any value). 
// Very nice solution.

int Solution::singleNumber(const vector<int> &A) 
{
	int BITS = 32 ;
	int ret = 0 ;
	
	int bitpos = 0, bitval = 1 ;
	
	for( bitpos = 0 ; bitpos < BITS ; bitpos++ )
	{
		int sum1 = 0 ;
		
		bitval = ( 1 << bitpos ) ;
		
		for( int i = 0 ; i < A.size() ; i++ )
		{
			if( bitval & A[i] )
				sum1++ ;
		}
		
		// The bits with sum not multiple of 3, are the bits of element with single occurrence.
		if( sum1 % 3 != 0 )
		{
			ret |= bitval ;
		}
	}

	return ret ;
}
