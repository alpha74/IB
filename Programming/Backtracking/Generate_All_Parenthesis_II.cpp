// Time Comp: O(2^n)
// Keep adding opening brackets if count_open < count.
// Keep adding closing brackets if count_opnen > count_closed.


void backtrack( vector<string> &all, string row, int count_open, int count_closed, int &count )
{
    if( count_closed == count )
    {
        all.push_back( row ) ;
        return ;
    }
    
    if( count_open < count )
        backtrack( all, row + "(", count_open+1, count_closed, count ) ;
    
    if( count_open > count_closed )
        backtrack( all, row + ")", count_open, count_closed+1, count ) ;
    
    return ;
}

vector<string> Solution::generateParenthesis(int A) 
{
    vector<string> all ;
    string row = "" ;
    
    if( A > 0 )
    {
        backtrack( all, row, 0, 0, A ) ;
    }
    return all ;
}
