// Sort the array. Start pointers from 0 and 1.
// See conditions for moving pointers.

int Solution::diffPossible(const vector<int> &A, int B) 
{
	long long int i = 0, j = 1 ;
	int ret = 0 ;
	int size = A.size() ;
	
	if( size > 1 )
	{
	    vector<int> Ac ;
	    for( int i = 0 ; i < size ; i++ )
	    {
	        Ac.push_back( A[i] ) ;
	    }
	    sort( Ac.begin(), Ac.end() ) ;
	    
    	while( i < size && j < size && ret == 0 )
    	{
    	    long long int diff = Ac[j] - Ac[i] ;
    	    
    	    if( diff == B && i != j )
    	        ret = 1 ;
    	       
    	   else if( diff < B ) 
    	        j++ ;
    	   else
    	        i++ ;
    	    
    	}
	}
	return ret ;
}
