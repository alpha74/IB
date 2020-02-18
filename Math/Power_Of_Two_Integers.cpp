// Using log

int Solution::isPower(int A) 
{
    int found = 0 ;
    
    if( A == 1 )
        found = 1 ;
    else
    {
        for( int i = 2 ; i <= sqrt(A) && found == 0 ; i++ )
        {
            double val = log( A ) / log( i ) ;
            
            if( ( val - (int)val ) < 0.00000001 )
                found = 1 ;
        }
    }
    return found ;
}
