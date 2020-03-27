// Using mod

string Solution::convertToTitle(int A) 
{
    string s = "" ;
    
    while( A > 26 )
    {
        int rem = A % 26 ;
        
        if( rem == 0 )
        {
            rem = 26 ;
            A = A - 1 ;
        }
        
        s = s.insert( 0, 1, char(rem+64) ) ;
        
        A = A /26 ;
    }
    
    s.insert( 0, 1, char(A+64) ) ;
    
    return s ;
}
