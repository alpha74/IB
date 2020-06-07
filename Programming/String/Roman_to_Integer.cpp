// Scan last and second last.
// If second last is < last, it is a Roman Numeral like: IV
// Else: Add to solution.

// Roman char to Numeral
int getValue(char c)
{
    if( c == 'I' )
        return 1 ;
        
    else if( c == 'V' )
        return 5 ;
        
    else if( c == 'X' )
        return 10 ;
        
    else if( c == 'L')
        return 50 ;
        
    else if( c == 'C' )
        return 100 ;
        
    else if( c == 'D' )
        return 500 ;
        
    else
        return 1000 ;
}

int Solution::romanToInt(string A) 
{
    int sol = 0, last, sec_last ;
    
    // Reverse from last
    for( int i = A.size()-1 ; i >= 0; i-- )
    {
        // Reset
        sec_last = 0 ;
        last = 0 ;
        
        char c = A[i] ;
        last = getValue( A[i] ) ;
        
        if( i != 0 )
        {
            sec_last = getValue( A[i-1] ) ; 
        }
        
        sol = sol + last ;
        
        // If there is some combination of two chars
        if( sec_last < last )
        {
            sol = sol - sec_last ;
            i--;
        }
    }
    
    return sol;
}
