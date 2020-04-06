// Check for conditions:
/*
  1. White space infront
  2. Negative sign
  3. Positive sign
  4. 0 after sign
  5. Value out of bound
*/

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int num_digits( int a )
{
	int ret = 0 ;
	
	while( a > 0 )
	{
		ret++ ;
		a = a / 10 ;
	}
	
	return ret ;
}

int Solution::atoi(const string A) 
{
	bool isNeg = false ;
	int i = 0, ret = 0 ;
	
	// Skip white spaces if any infront
	i = 0 ;
	while( A[i] == ' ' )
	{
		i++ ;
	}
	
	// Continue only when first element is digit or -ve sign or +ve
	if( isdigit( A[i] ) || A[i] == '-' || A[i] == '+' )
	{
		// Check if the number is negative
		if( A[i] == '-' )
		{
			i++ ;
			isNeg = true ;
		}
		else if( A[i] == '+' )
		{
			i++ ;
		}
		else ;

		// Skip the 0s infront
		while( A[i] == '0' )
		{
			i++ ;
		}
		
		bool stop = false ;
		// Extract only numbers in new string
		while( isdigit( A[i] ) && stop == false )
		{			
			int temp = ret * 10 + ( A[i] - 48 ) ; 
			
			if( num_digits( temp ) <= num_digits( ret ) )
			{
				ret = MAX_INT ;
				stop = true ;
			}
			else
				ret = temp ;
				
			i++ ;
		}
		
		// Negative sign check
		if( isNeg == true )
		{		
			if( ret >= MAX_INT )
				ret = MIN_INT ;
			else
				ret = ret * -1 ;
		}
		else
		{
			// Check for number range	
			if( ret >= MAX_INT )
				ret = MAX_INT ;
			
		}
		return ret ;
	}
	
	return ret ;
}
