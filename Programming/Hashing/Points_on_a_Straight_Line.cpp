// Trick is to use slope not as a double type but a pair<int,int>
// Calculate slope between two points, and match with remaining points.

int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    int maxpoints = 0 ;
    
    map<pair<int, int>, int> slopes  ;
    int size = A.size() ;
    
    if( size == 1 || size == 2 )
        return size ;
    
    for ( int i = 0; i < size ; i++ )
    {
        slopes.clear();
        
        //same = 1 to handle case when there is only 1 point (X,Y).
		int same = 1, currMax = 0 ;
        
		for ( int j = i+1 ; j < size ; j++ )
        {
            int diffX = A[i] - A[j];
            int diffY = B[i] - B[j];
            
            if ( diffX == 0 && diffY == 0 )
            {
                ++same;
                continue;
            }
            
            if (diffX < 0)
            {
                diffX *= -1;
                diffY *= -1;
            }
            
            int hcf = __gcd( diffX, diffY ) ;
            
            // Reduce the diffY and diffX by dividing by GCD.
            diffX /= hcf ;
            diffY /= hcf ;
            slopes[ make_pair( diffX, diffY )]++ ;
            
            currMax = max( currMax, slopes[ make_pair( diffX, diffY ) ] ) ;
        }
        currMax += same ;
        maxpoints = max( currMax, maxpoints ) ;
    }
    return maxpoints ;
}
