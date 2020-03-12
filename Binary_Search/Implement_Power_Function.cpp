// Check for Mod of negative numbers.
// Important logic for odd powers.

int Solution::pow(int x, int n, int d) 
{
    // Check for n == 0
    if( n == 0 )
    {
        return 1 % d ;
    }
    
    long long int ret = 1, base = x ;
    
    while( n > 0 )
    {
        if( n % 2 == 0 )
        {
            base = ( base * base ) % d ;
            n = n / 2 ;
        }
        else
        {
            ret = ( ret * base ) % d ;
            n-- ;
        }
    }
    
    
    if( ret < 0 )
    {
        ret = ( ret + d ) % d ;
    }

    return ret ;
}
