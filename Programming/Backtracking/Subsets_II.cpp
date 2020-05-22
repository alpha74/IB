// Not uses extra space for storing duplicates.
// Same as Subsets
// Iterates over duplicates.

void backtrack(vector<int> &A, int i, vector<vector<int> > &all , vector<int> &subset )
{
    all.push_back( subset );
    
    for( ; i < A.size() ; i++ )
    {
        subset.push_back( A[i] ) ;
        backtrack( A, i+1, all, subset ) ;
        
        // Iterate over duplicates
        while( i + 1 < A.size() && A[i] == A[i+1] ) 
            i++ ;
        
        subset.pop_back() ;
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) 
{
    sort( A.begin(), A.end() ) ;
    
    vector<vector<int>> ret ;
    vector<int> subset ;
    
    backtrack( A, 0, ret, subset );
    
    return ret ;
}
