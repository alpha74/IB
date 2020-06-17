// Use inclusion-exclusion principle, else TLE.

#define ll long long int

// Calculate LCM
ll lcm( ll A, ll B)
{
    return A * ( B/ __gcd(A,B ) ) ;
}

int Solution::solve(int A, int B, int C, int D) 
{
    ll lcmAB( lcm(A,B) ) , lcmAC( lcm(A,C) ), lcmBC(lcm(B,C)) ;
    ll lcmABC( lcm( AB, C ) ) ;
    
    // Numbers less than D
    ll d = D - 1 ;
    
    // Assume set theory
    // A u B u C = A + B + C - (A^B + B^C + C^A ) + A^B^C
    return d/A + d/B + d/C -(d/lcmAB+d/lcmBC+d/lcmAC) + d/lcmABC;
}
