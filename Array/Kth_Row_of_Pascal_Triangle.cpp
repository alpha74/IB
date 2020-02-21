// Matrix approach. Return required row.

vector<int> Solution::getRow(int A) 
{
    vector< vector<int> > ret ;
    vector<int> temp ;
    
    A = A + 1 ;
    
    if( A == 0 )
        return temp ;

    temp.push_back( 1 ) ;
    ret.push_back( temp ) ;
    
    if( A == 1 )
        return temp ;
    
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
    return ret[A-1] ;
}
