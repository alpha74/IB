// Working code.
// Get max of these: A[size-1] * A[size-2] * A[size-3] and A[0] * A[1] * A[size-1].
// Above condition satisfies all cases.

int Solution::maxp3(vector<int> &A) 
{
    int prod = 0 ;
    int size = A.size() ;
    
   	sort( A.begin(), A.end() ) ;
   	
   	// If all positive
   	if( A[size-3] > 0 )
   		prod = A[size-1] * A[size-2] * A[size-3] ;
   		
   	// If all negative	
   	else if( A[size-3] < 0 && A[size-2] < 0 && A[size-1] <= 0 )
   		prod = A[size-3] * A[size-2] * A[size-1] ;
   		
   	
   	// If 
   	else if( A[size-1] >= 0 || A[size-2] >= 0 )
   		prod = A[size-1] * A[0] * A[1] ;

    // If max is formed by one +ve and two -ve numbers
	int prod2 = A[0] * A[1] * A[size-1] ;
    prod = max( prod, prod2 ) ;
    
    return prod ;
}
