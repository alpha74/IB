// Using Sieve of Erastosthenes

vector<int> Solution::sieve(int A) 
{
    vector<bool> prime ;
    
    for( int i = 1 ; i <= A+1 ; i++ )
    {
        prime.push_back( true ) ;
    }
    
    for( int i = 2 ; i*i <= A ; i++ )
    {
        if( prime[i] == true )
        {
            for( int j = i*i ; j <= A ; j += i )
            {
                prime[ j ] = false ;
            }
        }
    }
    
    vector<int> prime_numbers ;
    
    for( int i = 2 ; i <= A ; i++ )
    {
        if( prime[i] == true )
            prime_numbers.push_back( i ) ;
    }
    
    return prime_numbers ;
}
