// Same as Combination Sum
// Note: Duplicates are allowed here.
// Don't use same element again and again for combination : Use it only once.

void backtrack(int i, vector<int>& row, int sum, set<vector<int> >& all, vector<int>& A, int &B)
{
    if( sum == B )
    {
        all.insert( row ) ;
        return ;
    }
    
    else if( sum > B )
        return ;
        
    else if( i == A.size() ) 
        return ;
    
    row.push_back( A[ i ] ) ;
    sum += A[ i ] ;
    
    backtrack( i + 1, row, sum, all, A, B );
    
    sum -= row[ row.size()-1 ] ;
    row.pop_back();
    
    backtrack( i+1, row, sum, all, A, B) ;
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) 
{
    set<vector<int> > all ;
    vector<int> row, a ;
    
    // Sort the give narray
    sort( A.begin(), A.end() ) ;
        
    backtrack(0, row, 0, all, A, B ) ;
    
    // Copy set to vector
    vector<vector<int>> ret ;
    
    for( auto iter = all.begin() ; iter != all.end() ; iter++ )
    {
    	ret.push_back( *iter ) ;
	}
    
    sort( ret.begin(), ret.end() ) ;
    
    return ret ;
}



