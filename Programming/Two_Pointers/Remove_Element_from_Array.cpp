// Maintain two pointers.
// Hard corner case: When last element is to be removed.

int Solution::removeElement(vector<int> &A, int B) 
{
    long long int curr = 0, check = 0 ;
    long long int size = A.size() ;
    
    if( A[0] == B && size == 1 )
        curr = 0 ;
    
    else
    {
        while( check < size )
        {
            if( A[ check ] == B )
            {
                while( A[check] == B )
                {
                    check++ ;
                }
                A[ curr ] = A[ check ] ;
                
                check++ ;
                
                if( check <= size )
                    curr++ ;
            }
            else
            {
                A[ curr ] = A[ check ] ;
                curr++ ;
                check++ ;
            }
        }
    }
    return curr ;
}
