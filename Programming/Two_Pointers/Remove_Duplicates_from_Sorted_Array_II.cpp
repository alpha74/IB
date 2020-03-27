// Two pointer logic.

int Solution::removeDuplicates(vector<int> &A) 
{   
    int count = 0;
    int size = A.size();
    
    for( int i = 0; i < size; i++ )
    {
        if( i < size-2 && A[i] == A[i+1] && A[i] == A[i+2] ) 
            ;
        else
            A[ count++ ] = A[ i ] ;
    }
    return count;
}
