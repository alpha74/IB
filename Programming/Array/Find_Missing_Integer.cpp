// https://www.interviewbit.com/problems/first-missing-integer/
// Shift numbers <= 0 to left of array.
// Sort the remaining and match the sequence of numbers.

// Shift numbers <= 0 to left of array
int shift_neg_left( vector<int> &A )
{
   int i = 0, j = 0 ;
   
   for( j = 0 ; j < A.size() ; j++ )
   {
       if( A[j] <= 0 )
       {
           int temp = A[i] ;
           A[i] = A[j] ;
           A[j] = temp ;
           i++ ;
         }
   }
   
   return i ;
}

int Solution::firstMissingPositive(vector<int> &A) 
{
    int neg = shift_neg_left( A ) ;
    
    if( neg == A.size() )
        return 1 ;
    else
    {
        sort( A.begin() + neg, A.end() ) ;
        int ret = 1 ;
        
        for( ; neg < A.size() ; neg++ )
        {
            if( A[neg] != ret )
            {
                neg = A.size() ;
            }
            else
                ret++ ;
        }
        
        return ret ;
    }
}
