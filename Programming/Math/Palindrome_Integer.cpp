// Reverse the number

int Solution::isPalindrome(int A) 
{
    int n = A ;
    int ret = 0 ;
    
    if( A >= 0 )
    {
        int revn = 0 ;
        
        while( n > 0 )
        {
            revn = revn * 10 + (n%10) ;
            n = n / 10 ;
        }
        
        if( revn == A )
            ret = 1 ;
    }
    return ret ;
}
