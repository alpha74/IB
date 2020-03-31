// Get the max difference between A[j] - A[i] where j > i.

int Solution::maxProfit(const vector<int> &A) 
{
    int size = A.size() ;
    
    if( size > 1 )
    {
        int minElem = A[0] ;
        int maxDiff = A[1] - A[0] ;
        
        for( int i = 1 ; i < size ; i++ )
        {
            if( A[i] - minElem > maxDiff )
                maxDiff = A[i] - minElem ;
                
            if( A[i] < minElem )
                minElem = A[i] ;
        }
     
        if( maxDiff >= 0 )
            return maxDiff ;
        else
            return 0 ;
    }
    else
        return 0 ;
}
