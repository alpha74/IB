// Comparing with INT_MAX

int Solution::reverse(int A) 
{
    bool neg = false ;
    if( A < 0 )
        neg = true ;
    
    long long int n = abs(A) ;
    long long int revn = 0 ;
    
    while( n > 0 )
    {
        revn = revn * 10 + ( n % 10 ) ;
        n = n / 10 ;
    }
    
    
    
    if( revn > 2147483647 )
        revn = 0 ;
        
    else if( neg )
        revn = -1 * revn ;
    
    else ;
    
    return revn ;
}
