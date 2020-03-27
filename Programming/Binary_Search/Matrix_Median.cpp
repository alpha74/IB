// Question assumes (row*col) is always odd.
// Median occurs after (n/2) elements. Using this.

int Solution::findMedian(vector<vector<int> > &A) 
{
    int min = INT_MAX, max = INT_MIN ;
    int row = A.size(), col = A[0].size() ;
    
    // Find all min and max from matrix
    for( int i = 0 ; i < row ; i++ )
    {
        // First element of each row
        if( A[i][0] < min )
            min = A[i][0] ;
        
        // Last element of each row
        if( A[i][col-1] > max )    
            max = A[i][col-1] ;
    }
    
    // Median number will come after (n/2) numbers in single list.
    int leave = ( row * col + 1 ) / 2 ;
    
    while( min < max )
    {
        // Get middle element
        int mid = ( min + max ) / 2 ;
        
        int count = 0 ;
        // Get count of numbers smaller than mid in each row
        for( int i = 0 ; i < row ; i++ )
        {
            count += upper_bound( A[i].begin(), A[i].end(), mid ) - A[i].begin() ;
        }
        
        if( count < leave )
            min = mid + 1 ;
        else
            max = mid ;
    }
    
    return min ;
}
