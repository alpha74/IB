// Using extra space.

int Solution::removeDuplicates(vector<int> &A) 
{
    set<int> uniq ;
    int size = A.size() ;
    
    int ret = 0 ;
    
    for( int i = 0 ; i < size ; i++ )
    {
        uniq.insert( A[i] ) ;
    }
    
    for( auto iter = uniq.begin() ; iter != uniq.end() ; iter++ )
    {
        ret++ ;
        
        A[i] = *iter ;
    }
    
    return ret ;
}
