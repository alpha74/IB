// Best approach is to move all to median position of sitting people.

#define MOD 10000003

int Solution::seats(string A) 
{
    vector<int> seats ;
    
    for( int i = 0 ; i < A.length() ; i++ )
    {
        if( A[i] == 'x' )
            seats.push_back( i ) ;
    }
    
    long long int jumps = 0 ;
    
    int mid = seats.size() / 2 ;
    
    int k = 1 ;
    for( int i = mid -1 ; i >= 0 ; i-- )
    {
        jumps = ( jumps + seats[mid] - ( seats[i] + k )) % MOD ;
        k++ ;
    }
    k = 1 ;
    
    for( int i = mid + 1 ; i < seats.size() ; i++ )
    {
        jumps = (jumps + seats[i] - ( seats[mid] + k )) % MOD ;
        k++ ;
    }
    
    return jumps % MOD ;
}
