// Same as Subset
// Using <set> to store only unique values.

void backtrack(vector<int> &A, int i, set<vector<int> > &all , vector<int> &subset )
{
    all.insert( subset );
    for( ; i < A.size() ; i++ )
    {
        subset.push_back( A[i] ) ;
        backtrack( A, i+1, all, subset ) ;
        subset.pop_back() ;
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    sort( A.begin(), A.end() ) ;
    
    set<vector<int>> ret ;
    vector<int> subset ;
    
    backtrack( A, 0, ret, subset );
    
    vector<vector<int>> slist ;
    
    for( auto iter = ret.begin() ; iter != ret.end() ; iter++ )
    {
    	slist.push_back( *iter )  ;
 	}
    
    return slist ;
}
