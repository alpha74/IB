// Using extra space for storing order and frequency.

void Solution::sortColors(vector<int> &A) 
{
    map<int,int> uniq ;
    set<int> order ;
    
    for( int i = 0 ; i < A.size() ; i++ )
    {
        auto iter = uniq.find( A[i] ) ;
        order.insert( A[i] ) ;
        
        if( iter == uniq.end() )
        {
            uniq.insert( pair<int,int>( A[i], 1 ) ) ;
        }
        else
        {
            iter -> second = iter -> second +1 ;
        }
    
    }
    
    int index= 0 ;
    
    for( auto iter = order.begin() ; iter != order.end(); iter++ )
    {
        int val = *iter ;
        auto iter2 = uniq.find( val ) ;
        int freq = iter2 -> second ;
    
        while( freq-- )
        {
            A[index++] = val ;
        }
    
    }
    
}
