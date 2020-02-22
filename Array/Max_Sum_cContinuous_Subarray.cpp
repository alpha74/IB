// Using Kadane's algo.

int Solution::maxSubArray(const vector<int> &A) 
{
    int curr_max = A[0], total_max = A[0] ;
    
    for( int i = 1 ; i < A.size() ; i++ )
    {
        curr_max = max( A[i], curr_max + A[i] ) ;
        
        total_max = max( total_max, curr_max ) ;
    }
    
    return total_max ;
}
