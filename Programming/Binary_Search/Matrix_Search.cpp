// Apply binary search in each row.

int binSearch( vector<int> A, int start, int end, int B )
{
    int ret = -1 ;
    if( start == end )
        return ret ;
        
    else
    {
        while( start <= end && ret == -1 )
        {
            if( A[ start ]== B || A[ end ] == B )
                ret = 1 ;
            else
            {
                int mid = ( start + end ) / 2 ;
                
                if( A[ mid ]== B )
                {
                    ret = mid ;
                }
                else if( B > A[ mid ])
                {
                    start = mid + 1 ;
                }
                else
                {
                   end = mid - 1;
                }
            }
        }
        return ret ;
    }
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int m = A.size() ;
    int n =  A[ 0 ].size() ;
    
    int found = 0 ;
    int mi = 0, ret = 0 ;
    
    for( int i = 0 ; i < m && found == 0 ; i++ )
    {
        if( B >= A[i][0] && B <= A[i][n-1] )
        {
            if( B == A[i][0] || B == A[i][n-1] )
            {
                found = 2 ;
                mi = i ;
            }
            else
            {
                mi = i ;
                found = 1 ;
            }
        }
    }
    if( found == 2 )
    {
        ret = 1 ;
    }
    else if( found == 1 )
    {
        ret = binSearch( A[mi], 0, n - 1, B ) ;
        
        if( ret == -1 )
            ret = 0 ;
        else
            ret = 1 ;
    }
    else
        ret = 0 ;
    
    return ret ;
}
