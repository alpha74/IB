// Using factorial formula

int Solution::trailingZeroes(int n) 
{
    int five = 5 ;
    int zeros = 0 ;
    
    while( five =< n )
    {
        zeros = zeros + n / five ;
        
        five = five * 5 ;
    }
    
    return zeros ;
}
