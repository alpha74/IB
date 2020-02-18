// Using Dynamic Programming approach

int Solution::uniquePaths(int A, int B) 
{
    vector<vector<int>> paths ;
    
    int ret = -1 ;
    
    if( A == 1 || B == 1 )
        ret = 1 ;
    else
    {
        for( int i = 0 ; i < A ; i++ )
        {
            vector<int> temp ;
            for( int j = 0 ; j < B ; j++ )
            {
                if( i == 0 || j == 0 )
                    temp.push_back( 1 ) ;
                else
                    temp.push_back( 0 ) ;
            }
            paths.push_back( temp ) ;
        }
        
        for( int i = 1 ; i < A ; i++ )
        {
            for( int j = 1 ; j < B ; j++ )
            {
                paths[ i ][ j ] = paths[ i - 1 ][j] + paths[i][j-1] ;
            }
        }
        
        ret = paths[A-1][B-1] ;
    }
    
    return ret ;
}
