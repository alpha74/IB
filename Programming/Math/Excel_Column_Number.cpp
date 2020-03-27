// Using ASCII values

int Solution::titleToNumber(string A) 
{
    int ret = 0 ;
    
    // Get length of string
    int len = A.length() ;
    
    for( int i = len -1 ; i >= 0 ; i-- )
    {
        ret = ret + pow( 26, (len-1)-i) * (int(A[i])-64) ;
    }
    
    return ret ;
}
