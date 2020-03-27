// Use long long int; OR Reduce j as commented.

int Solution::sqrt(int A) 
{
	int i = 1, j = A ;
	
  /*
    if( j > 1000000000 )
      j= j/4 ;
  */
	
	int lmid = -1 ;
	
	int root = -1 ;
	
	if( A < 2 )
		root = A ;
	else
	{
		while( i < j && root == -1 )
		{
			int mid = ( i + j ) / 2 ;
			
			if( mid == A/mid )
			{
				root = mid ;
			}
			else if( mid > A/mid )
				j = mid ;
			else
				i = mid ;
				
			if( lmid == mid )
			{
				root = mid ;	
			}
			else
				lmid = mid ;
		}
	}
		
	return root ;
}
