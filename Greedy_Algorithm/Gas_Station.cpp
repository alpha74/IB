// O(n) solution.
// Pairwise comparison if next station can be reached from current.

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int sumGas = 0 ;
    int sumCost = 0 ;
    int start = 0 ;
    int tank = 0 ;
    
    int size = A.size() ;
    
    for( int i = 0 ; i < size ; i++ )
    {
        sumGas += A[i] ;
        sumCost += B[i] ;
        
        tank = tank + A[i] - B[i] ;
        
        if( tank < 0 )
        {
            start = i + 1 ;
            tank = 0 ;
        }
    }
    
    if( sumGas < sumCost )
    {
        start = -1 ;
    }
    
    return start ;
}
