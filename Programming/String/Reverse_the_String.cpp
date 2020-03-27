// Use stack for storing individual words.

string Solution::solve(string A) 
{
	int i = 0 ;
	int size = A.length() ;
	
	string ret = "" ;
	string curr = "" ;
	stack<string> rev ;
	
	
	// Iterate over the initial spaces
	while( A[i] == ' ' )
	{
		i++ ;
	}
	
	for( ; i < size ; i++ )
	{
		if( A[i] == ' ' )
		{
			
			rev.push( curr ) ;
				
			curr = "" ;
			
			while( A[i] == ' ' ) 
			{
				i++ ;
			}
			i-- ;
		}
		else
		{
			if( A[i] != '.' || A[i] != ' ' )
				curr += A[i] ;
		}
	}
	
	if( curr.length() > 0 )
		rev.push( curr ) ;
	
	// Pop from stack and append in string
	// Do for first
	if( !rev.empty() )
	{
		ret = rev.top() ;
		rev.pop() ;
	}
	
	while( !rev.empty() )
	{
		ret += " " ;
		
		ret = ret + rev.top() ;
		rev.pop() ;
	}
	
	
	return ret ;
}
