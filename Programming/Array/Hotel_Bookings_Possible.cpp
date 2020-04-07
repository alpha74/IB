// Use two pointers in each array, after sorting, and manipulate K.
// Check when K becomes 0.

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    int a = 0, d = 0 ;
    int sizea = arrive.size() ;
    int sized = depart.size() ;
    
    bool possible = true ;
    
    sort( arrive.begin(), arrive.end() ) ;
    sort( depart.begin(), depart.end() ) ;
    
    while( a < sizea && d < sized && possible == true )
    {
        if( arrive[a] == depart[d] )
        {
            a++ ;
            d++ ;
        }
        else if( arrive[a] < depart[d] )
        {
            if( K > 0 )
                K-- ;
            else
                possible = false ;
                
            a++ ;
        }
        else
        {
            K++ ;
            d++ ;
        }
    }
    
    if( possible == true )
    {
        if( a < sizea )
            possible = false ;
    }
    
    return possible ;
}
