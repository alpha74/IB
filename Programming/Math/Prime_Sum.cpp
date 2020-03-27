// Implemented only the function.

vector<int> get_primes( int n )
{
    vector<bool> prime ;
    
    for( int i = 1 ; i <= n + 1 ; i++ )
    {
        prime.push_back( true ) ;
    }
    
    for( int i = 2 ; i*i <= n ; i++ )
    {
        if( prime[i] == true )
        {
            for( int j = i*i ; j <= n ; j += i )
            {
                prime[j] = false ;
            }
        }
    }
    
    vector<int> ret ;
    
    for( int i = 2 ; i <= n ; i++ )
    {
        if( prime[i] == true )
        {
            ret.push_back( i ) ;
            //cout << i << " " ;
        }
    }
    
    return ret ;
}

vector<int> Solution::primesum(int A) 
{
    vector<int> primes ;
    // Get list of all primes
    primes = get_primes( A ) ;
    
    vector<int> ret ;
    
    int i = 0, j = primes.size() -1 ;
    
    while( i <= j )
    {
        int sum = primes[i] + primes[j] ;
        
        if( sum == A )
        {
            ret.push_back( primes[i] ) ;
            ret.push_back( primes[j] ) ;
            break ;
        }
        else if( sum < A )
        {
            i++ ;
        }
        else
            j-- ;
    }
    
    return ret ;
}
