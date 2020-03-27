// Using simple if-else and ASCII to char conversion.
// Using string insertion at 0

string num_to_str( int n )
{
    string ret = "" ;
    
    if( n < 10 )
        ret.push_back( char(n+48) ) ;
        
    else
    {
        while( n > 0 )
        {
            ret.insert( 0, 1, char( ( n% 10 ) + 48 ) ) ;
            n = n/ 10 ;
        }
    }
    return ret ;
}

vector<string> Solution::fizzBuzz(int A) 
{
    vector<string> ret ;
    
    string F = "Fizz" ;
    string B = "Buzz" ;
    string FB = "FizzBuzz" ;
    
    for( int i = 1 ; i <= A ; i++ )
    {
        if( i % 3 == 0 && i % 5 == 0 )
            ret.push_back( FB ) ;
        
        else if( i % 3 == 0 )
            ret.push_back( F ) ;
    
        else if( i % 5 == 0 )
            ret.push_back( B ) ;
            
        else 
        {
            ret.push_back( num_to_str( i ) ) ;
        }    
    }
    
    return ret ;
}

