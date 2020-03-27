// Use extra space to store the frequency of numbers.

int Solution::majorityElement(const vector<int> &A) 
{
    map<int,int> freq ;
    int size = A.size() ;
    int lim = size / 2 ;
    int ret = -1 ;
    
    for( int i = 0 ; i < size && ret == -1 ; i++ )
    {
        auto iter = freq.find( A[i] ) ;
        
        if( iter == freq.end() )
        {
            freq.insert( pair<int,int> ( A[i], 1 ));
            
            if( ( iter -> second + 1 ) > lim )
                ret = A[i] ;
        }
        else
        {
            iter -> second = iter -> second + 1 ;
            
            if( iter -> second > lim )
                ret = A[i] ;
        }
    }
    
    return ret ;
}
