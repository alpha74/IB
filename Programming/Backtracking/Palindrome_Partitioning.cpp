// Same backtracking rules as other questions. 
// Do recursive call to backtrack() only when current string is palindrome.

// Check if passed string is a palindrome or not.
bool checkPalindrome( string &A )
{
	if( A.length() == 1 )
		return true ;
	
	int i = 0 ;
	int j = A.length() -1 ;
	
	bool ret = true ;
	
	while( i < j && ret == true )
	{
		if( A[i] != A[j] )
			ret = false ;
		
		i++ ;
		j-- ;
	}
	return ret ;
}

void backtrack( vector<vector<string>> &all, vector<string> &curr, int i, string &A )
{
	int len = A.length() ;
	
	if( i == len )
	{
		all.push_back( curr ) ;
		return ;
	}
	
	string str = "" ;
	
	for( ; i < len ; ++i )
	{
		str = str + A[i] ;
		
		if( checkPalindrome( str ) == true )
		{
			curr.push_back( str ) ;
			
			backtrack( all, curr, i+1, A ) ;
			
			curr.pop_back() ;
		}
	}
	
	return ;
}

vector<vector<string> > Solution::partition(string A)
{
    // Result list
	vector<vector<string>> all ;
	// Current list
	vector<string> curr ;
	
	int i = 0 ;
	
	backtrack( all, curr, i, A ) ;
	
	return all ;
}
