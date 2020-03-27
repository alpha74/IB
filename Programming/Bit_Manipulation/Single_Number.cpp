// Using XOR property of
//  - XOR between same number gives 0.
//  - XOR of a number with 0 gives number itself.

int Solution::singleNumber(const vector<int> &A) 
{
    int x = 0 ;
    
    for( int i = 0 ; i < A.size() ; i++ )
    {
        x = x ^ A[i] ;
    }
    
    return x ;
}
