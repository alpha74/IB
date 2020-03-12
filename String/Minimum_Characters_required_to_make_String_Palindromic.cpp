// Remove last element and check if current string is palindrome. If not increment count, remove again and continue.

bool ispalindrome( string &A, int i, int j )
{
    bool ret = true ;
    int size = A.length() ;
    
    for( ; i < j && ret == true ; i++,j--)
    {
        if( A[i] != A[j] )
        {
            ret = false ;
        }
    } 
    
    return ret ;
}

int Solution::solve(string A) 
{
    int size = A.length() ;
    int ret = 0 ;
    
    if( size > 1 )
    {
        int i = 0, j = size -1 ;
        
        bool done = false ;
        
        while( !done && j > 0 )
        {
            if( ispalindrome( A, i, j ) == true )
                done = true ;
            else
            {
                ret++ ;
                j-- ;
            }
        }
        
    }
    else
    {
        ret = 0 ;
    }
    
    return ret ;
}
