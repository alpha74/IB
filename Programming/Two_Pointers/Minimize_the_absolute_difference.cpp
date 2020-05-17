// Iterate from last of each array as they are the max.
// Update the mindiff.
// Decrement the pointer of max of three.

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
	int mindiff = INT_MAX ;
	
	int pa = A.size()-1, pb = B.size()-1, pc = C.size()-1 ;
	
	while( pa >= 0 && pb >= 0 && pc >= 0  )
	{
		int maxelem = max( A[pa], max( B[pb], C[pc] ) ) ;
		int minelem = min( A[pa], min( B[pb], C[pc] ) ) ;
		
		int currdiff = maxelem - minelem ;
		mindiff = min( mindiff, currdiff ) ;
		
		if( maxelem == A[pa] )
			pa-- ;
		
		else if( maxelem == B[pb] )
			pb-- ;
			
		else
			pc-- ;
	}
	
	return mindiff ;
}
