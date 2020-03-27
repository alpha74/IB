// Using Euclidean algorithm

int Solution::gcd(int A, int B) 
{
    while( B > 0 )
    {
        int c = A % B ;
        A = B ;
        B = c ;
    }
    
    return A ;
}
