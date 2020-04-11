// Simple backtracking trick.
// See call of backtrack() and its definition.

void backtrack( int i, vector<vector<int>> &all, vector<int> &comb, int &A, int &B )
{
	if( comb.size() == B )
	{
		all.push_back( comb ) ;
		return ;
	}
	else
	{
		for( ; i <= A ; i++ )
		{
			comb.push_back( i ) ;
			backtrack( i + 1, all, comb, A, B ) ;
			comb.pop_back() ;
		}
	}
	
}

vector<vector<int> > Solution::combine(int A, int B)
{
	int i = 0 ;
	
	vector<vector<int>> all ;
	vector<int> comb ;
	
	for( int i = 1 ; i <= A ; i++ )
	{
		comb.push_back( i ) ;
		
		backtrack( i+1, all, comb, A, B ) ;
		
		comb.pop_back() ;
	}
	
	return all ;
}
