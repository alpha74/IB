// Backtracking trick. See backtrack() and its call.

void backtrack(int i, vector<int>& row, int sum, vector<vector<int> >& all, vector<int>& A, int &B)
{
    if( sum == B )
    {
        all.push_back( row ) ;
        return ;
    }

    else if( sum > B )
        return ;

    else if( i == A.size() ) 
        return ;


    row.push_back( A[ i ] ) ;
    sum += A[ i ] ;

    backtrack( i, row, sum, all, A, B);

    sum -= row[ row.size()-1 ] ;
    row.pop_back();

    backtrack( i+1, row, sum, all, A, B) ;
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B) 
{
    vector<vector<int> > all ;
    vector<int> row, a ;

    sort( A.begin(), A.end() ) ;

    a.push_back( A[0] ) ;

    // Remove duplicates
    for ( int i = 1 ; i < A.size() ; i++ )
    {
        if (A[i-1] != A[i])
            a.push_back(A[i]);
    }

    backtrack(0, row, 0, all, a, B ) ;

    return all ;
}

