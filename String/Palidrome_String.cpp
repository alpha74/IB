// Separating alphanumeric characters.

int Solution::isPalindrome(string A) 
{
    string B = "" ;
    
    for( int i = 0 ; i < A.length() ; i++ )
    {
        if( isalpha( A[i]) || isdigit( A[i]) )
            B += tolower( A[i] ) ;
    }
    
    int i = 0, j = B.length() - 1 ;
    
    int ret = 1 ;
    
    for( ; i < ( B.length() /2 ) && ret == 1 ; i++, j--  )
    {
        if( B[i] != B[j] )
            ret = 0 ;
    }
    
    return ret ;
}
