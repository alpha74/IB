// Iterate linearly.
// Reduce the time of right propagation using XOR. See usage of variable 'inv'

int Solution::bulbs(vector<int> &A) 
{
    int size = A.size() ;
    int ret = 0 ;
    
    if( size == 1 && A[0] == 1 )
        return 0 ;
    else if( size == 1 && A[0] == 0 )
        return 1 ;
    
    // XOR the bulb value with it to represent the switch pressing right propagation
    int inv = 0 ;
    
    for( int i = 0 ; i < size ; i++ )
    {
        // Skip all ON bulbs
        while( A[i] ^ inv == 1 && i < size )
        {
            i++ ;
        }
        
        if( i < size )
        {
            // Switch pressed
            ret++ ;
        }
        
        inv = ( inv == 1 ) ? 0 : 1 ;
        
    }
        
    
    return ret ;    
}
