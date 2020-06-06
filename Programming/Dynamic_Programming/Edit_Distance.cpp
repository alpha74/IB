// DP
// Read the comments

int Solution::minDistance(string A, string B) 
{
    int sizeA = A.length() ;
    int sizeB = B.length() ;
    
    // Create 2D array of (sizeA+1, sizeB+1) 
    vector<vector<int>> dist( sizeA+1, vector<int> ( sizeB+1, 0 ) ) ;
    
    // Fill this array
    for( int i = 0 ; i < sizeA+1 ; i++ )
    {
        for( int j = 0 ; j < sizeB+1 ; j++ )
        {
            // If base string is NULL and target is NOT NULL, operation: ADD
            if( i == 0 )
                dist[i][j] = j ;
                
            // If target is NULL and base in NOT NULL, operation: ADD    
            else if( j == 0 )
                dist[i][j] = i ;
                
            // If base and target chars match, get diagonally opposite value
            else if( A[i-1] == B[j-1] )
                dist[i][j] = dist[i-1][j-1] ;
                
            // If base and target chars do not match, get min( LEFT, TOP, DIAGONALLY OPPOSITE )
            else
                dist[i][j] = 1 + min( dist[i-1][j-1], min( dist[i][j-1], dist[i-1][j] ) ) ;
        }
    }
    
    return dist[sizeA][sizeB] ;
}
