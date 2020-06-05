// https://www.interviewbit.com/problems/flip/

// Use two pointer approach. Check for difference between num of 1s and 0s, and move pointers.
// Check condition for discarding whole subarray.

vector<int> Solution::flip(string A) 
{
    int size = A.size() ;
    vector<int> ret ;
    
    int i = 0, j = 0 ;
    
    int diff = 0 ;      // Difference between number of 1s and 0s
    int maxdiff = 0 ;
    int ret1 = -1, ret2 = -1 ;
    
    while( j < size )
    {
        // Check current element
        diff += ( A[j] == '0' ) ? 1 : -1 ; 
        
        if( diff < 0 )
        {
            i = j + 1 ;
            diff = 0 ;
        }
        else
        {
            if( diff > maxdiff )
            {
                ret1 = i + 1 ;
                ret2 = j + 1 ;
                
                maxdiff = diff ;
            }
        }
        
        j++ ;
    }
    
    
    if( ret1 != -1 )
    {
        ret.push_back( ret1 ) ;
        ret.push_back( ret2 ) ;
    }
    
    return ret ;
}
