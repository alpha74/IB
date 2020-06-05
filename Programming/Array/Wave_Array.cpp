// https://www.interviewbit.com/problems/wave-array/

// Sort and Swap

vector<int> Solution::wave(vector<int> &A) 
{
    int n = A.size() ;
    
    if( n == 1  )
        return A ;
    else
    {
        sort( A.begin(), A.end() ) ;
        // Make first element greater than second
        int temp = 0, i = 0 ;
        
        // Choose 2 elements at a time and set left element as max of two.
        for( i = 0 ; (i+1) < n ; i+=2 )
        {
            temp = A[i] ;
            A[i] = A[i+1] ;
            A[i+1]= temp ;
        }
        
        return A ;
    }
}
