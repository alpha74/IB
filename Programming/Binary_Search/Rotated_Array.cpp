// Do binary search till i < j.
// Final value of i is solution index.

// 5 6 7 1 2 3 4
// 0 1 2 3 4 5 6

int Solution::findMin(const vector<int> &A) 
{
    int i = 0, j = A.size() - 1 ;
    
    while (i < j) 
    {
        int mid = (i+j) / 2 ;
        
        if( A[ mid ] > A[ j ]) 
            i = mid + 1;
        else 
            j = mid;
    }
    return A[i] ;
}
