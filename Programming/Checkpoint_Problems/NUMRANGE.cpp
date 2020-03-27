// Get count of sub-arrays having sum <= C, and for (B-1)
// Return their difference

int countSub( vector<int> &A, int L )
{
    // Returns number of sub-arrays having sum <= L
    int start = 0, end = 0 ;
    int count = 0, sum = 0 ;
    int size = A.size() ;
    
    while( end < size )
    {
        sum += A[ end ] ;
        
        while( start <= end && sum > L )
        {
            sum -= A[ start ] ;
            start++ ;
        }
        
        count = count + ( end - start + 1 );
        end++ ;
        
    }
    
    return count ;
}

int Solution::numRange(vector<int> &A, int B, int C) 
{
    // Count of sub-arrys having sum <= L
    int countC = countSub( A, C ) ;
    // Count of sub-arrays having sum <= (B-1)
    int countB = countSub( A, B-1) ;
    
    // Result is count of sub-arrays having sum in given range
    return countC - countB ;
}
