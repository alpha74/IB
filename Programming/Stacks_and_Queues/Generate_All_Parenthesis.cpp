// Use stack.
// Push for opening bracket, and pop for closing.
// Check cases for poping, and getting top.


// Returns closing char of corresponding bracket.
char getInverse( char &A )
{
	char ret = 'X' ;
	
	switch( A ) 
	{
		case '(' :	ret = ')' ;		break ;
		case '{' :	ret = '}' ;		break ;
		case '[' :	ret = ']' ;		break ;
	}
	
	return ret ;
}

int Solution::isValid(string A) 
{
	stack<char> stk ;
	
	int ret = 1 ;
	int size = A.length() ;
	
	for( int i = 0 ; i < size && ret == 1 ; i++ )
	{
		if( A[i] == '(' || A[i] == '{' || A[i] == '[' )
			stk.push( A[i] ) ;
		else
		{
			if( stk.empty() )
				ret = 0 ;
			else
			{
				char last = stk.top() ;
				
				if( getInverse( last ) == A[i] )
				{
					if( stk.empty() )
						ret = 0 ;
					else
						stk.pop() ;
				}
				else
					ret = 0 ;
			}
		}	
	}
	
	if( !stk.empty() )
		ret = 0 ;
	
	return ret ;
}
