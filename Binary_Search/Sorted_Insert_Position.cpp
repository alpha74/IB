// Using custom conditions in Binary Search

int Solution::searchInsert(vector<int> &A, int B) 
{
    int ret = -1 ;
    
    int i = 0, j = A.size() - 1 ;
    
    if( B < A[0] )
		ret = 0 ;
		
	else if( B > A[ j ] )
		ret = j+1 ; 
    else
    {
        bool stop = false ;
	    while( i <= j && stop == false )
	    {
	        int mid = (i+j) / 2; 
	        
	        if( B == A[mid] )
	        {
	            ret = mid ;
	            stop = true ;
	        }
	        else
	        {
	            if( A[ mid ] < B && A[mid+1] > B )
	            {
	                ret = mid + 1 ;
	                stop = true ;
	            }
	            else if( A[ mid - 1 ] < B && A[ mid ] > B )
	            {
	            	ret = mid ;
	            	stop = true ;
				}
	            else
	            {
	                if( B > A[mid] )
	                    i = mid ;
	                else
	                    j = mid ;
	            }
	        }
	    }
	}
	    
    return ret ;
}
