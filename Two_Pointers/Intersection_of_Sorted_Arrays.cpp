// Simple two pointer equality approach

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) 
{
    int pa = 0 ;
    int pb = 0 ;
    
    int sizeA = A.size(), sizeB = B.size() ;
    
    vector<int> ret ;
    
    while( pa < sizeA && pb < sizeB )
    {
        if( A[pa] == B[pb] )
        {
            ret.push_back( A[pa] ) ;
            pa++ ;
            pb++ ;
        }
        else if( A[pa] > B[pb] )
            pb++; 
        
        else
            pa++ ;
        
    }
    
    return ret ;
}
