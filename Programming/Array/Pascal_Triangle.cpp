// https://www.interviewbit.com/problems/pascal-triangle/

// Matrix approach

vector<vector<int> > Solution::solve(int A) 
{
    vector< vector<int> > ret ;
    
    if( A == 0 )
        return ret ;
    
    vector<int> temp ;
    temp.push_back( 1 ) ;
    ret.push_back( temp ) ;
    
    if( A == 1 )
        return ret ;
    
    for( int i = 2 ; i <= A; i++ )
    {
        vector<int> line ;
        
        for( int j = 0 ; j < i ; j++ )
        {
            if( j == 0 || j == ( i-1 ) )
            {
                line.push_back( 1 ) ;
            }
            else
            {
                line.push_back( ret[i-2][j-1] + ret[i-2][j] ) ;
            }
        }
        ret.push_back( line ) ;
    }
    return ret ;
}
