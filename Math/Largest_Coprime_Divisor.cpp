// Using gcd

int gcd( int A, int B )
{
    if( A == 0 || B == 0 )
        return 0 ;
        
    if( A == B )
        return A ;
        
    if( A > B )
    {
        return gcd( A-B, B ) ;
    }
    return gcd( A, B - A ) ;
}

int Solution::cpFact(int A, int B) 
{
    while( gcd( A, B ) != 1 )
    {
       A = A / gcd( A, B ) ; 
    }
    return A ;
}
