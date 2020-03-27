// Jump to level 3 question
// PRETTYPRINT
// Approach is use min(i,j) in two separate nested loops

vector<vector<int> > Solution::prettyPrint(int A) 
{
    int n = A ;
    vector< vector<int>> ret ;
	
	// 0 -> n-1
	int i = 0 ;
	for( i = 0 ; i < n ; i++ )
	{
		int j ;
		vector<int> line ;
		
		for( j = 0 ; j < n ; j++ )
		{
			line.push_back( n - min( i, j ) ) ;
		}
		
		j -= 2 ;
		
		for( ; j >= 0 ; j-- )
		{
			line.push_back( n - min( i, j )) ;
		}
		
		ret.push_back( line ) ;
	}
	
	// n-2 -> 0
	i -= 2 ;
	
	for( ; i >= 0 ; i-- )
	{
		int j ;
		vector<int> line ;
		
		for( j = 0 ; j < n ; j++ )
		{
			line.push_back( n - min( i, j ) ) ;
		}
		
		j -= 2 ;
		
		for( ; j >= 0 ; j-- )
		{
			line.push_back( n - min( i, j )) ;
		}
		
		ret.push_back( line ) ;
	}
	
	return ret ;
}
