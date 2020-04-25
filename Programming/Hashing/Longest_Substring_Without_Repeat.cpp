// Use two pointer approach.
// Use a map to maintain the greatest index of a character encountered so far to quickly shrink the window.

int Solution::lengthOfLongestSubstring(string A) 
{
    int size = A.size() ;
    
    if( size <= 1 )
        return size ;;
    
    int maxlen = 1 ;
 
    map<char,int> substring ;
    int i = 0, j = 0 ;
    
    while( j < size )
    {
        auto iter = substring.find( A[j] ) ;
        
        if( iter == substring.end() )
        {
            substring.insert( pair<char,int>( A[j], j ) ) ;
            j++ ;
        }
        else
        {
            auto iteri = substring.find( A[j] ) ;
            int c = iteri -> second ;
            
            while( i <= c )
            {
                substring.erase( A[i] ) ;
                
                i++ ;
            }
            
        }
        
        
        if( (j-i) > maxlen )
            maxlen = substring.size() ;
    }
 
    return maxlen ;   
}
