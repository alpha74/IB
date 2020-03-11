// Start two pointers from 0 and 1. Move the pointers accordingly.

int Solution::diffPossible(vector<int> &A, int B) 
{
	long long int i = 0, j = 1 ;
	int ret = 0 ;
	
	while( i < A.size() && j < A.size() && ret == 0 )
	{
	    long long int diff = A[j] - A[i] ;
	    
	    if( diff == B && i != j )
	        ret = 1 ;
	       
	   else if( diff < B ) 
	        j++ ;
	   else
	        i++ ;
	    
	}
	
	return ret ;
}
