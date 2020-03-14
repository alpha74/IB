// Brute Force solution
// Start from each gas station, and check if same gas station can be reached.

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    
    long long int i = 0, j = 0 ;
    int ret = -1 ;
    long long int size = A.size() ;
    
    
    for( i = 0 ; i < size && ret == -1 ; i++ )
    {
        long long int gas = 0 ;
        
        bool canDo = true ;
        
        for( j = i ; j < size && canDo == true ; j++ )
        {
            gas = gas + A[ j ] - B[ j ] ;
                    
            if( gas < 0 )
                canDo = false ;
        }
        
        for( j = 0 ; j < i && canDo == true ; j++ )
        {
            gas = gas + A[ j ] -B[ j ] ;
            
            if( gas < 0 )
                canDo = false ;
        }
        
        if( canDo == true )
            ret = i ;
    }
    
    return ret ;
}
