// Using custom comparator using strings.

bool lcompare( string A, string B )
{
    string AB = A.append( B ) ;
    string BA = B.append( A ) ;
    
    if( BA > AB )
        return false ;
    else
        return true ;
}

string Solution::largestNumber(const vector<int> &A) 
{
    vector<string> B ;
    
    bool all_zero = true ;
    
    for( int i = 0 ; i < A.size() ; i++ )
    {
        if( A[i] != 0 )
            all_zero = false ;
        
        B.push_back( to_string( A[i] ) ) ;
    }
    
    string ret = "" ;
    
    if( all_zero == false )
    {
        sort( B.begin(), B.end(), lcompare ) ;
        
        for( int i = 0 ; i < B.size() ; i++ )
        {
            ret.append( B[i] ) ;
        }
    }
    else
    {
        ret = "0" ;
    }
    
    return ret ;
}
