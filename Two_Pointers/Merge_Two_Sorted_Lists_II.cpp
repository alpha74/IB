// Simple two pointer approach. Focus on equality condition.

void Solution::merge(vector<int> &A, vector<int> &B) 
{
    int pa = 0, pb = 0 ;
    int sizeA = A.size(), sizeB = B.size() ;
    vector<int> ret ;
    
    while( pa < sizeA && pb < sizeB )
    {
        if( A[pa] < B[pb] )
        {
            ret.push_back( A[pa] ) ;
            pa++ ;
          
        }
        else if( B[pb] < A[pa] )
        {
            ret.push_back( B[pb] ) ;
            pb++ ;
       
        }
        else
        {
            ret.push_back( A[pa] ) ;
            ret.push_back( B[pb] ) ;
            pa++ ;
            pb++ ;
            
        }
    }
    
    if( pa < sizeA )
    {
    	for( ; pa < sizeA ; pa++ )
    		ret.push_back( A[pa] ) ;
	}
	if( pb < sizeB )
	{
		for( ; pb < sizeB ; pb++ )
			ret.push_back( B[pb] ) ;
	}
    
    A = ret ;
}
