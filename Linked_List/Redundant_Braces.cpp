// If any arithematic operator comes between two braces, then it does not have Redundant braces.
// Parse and push it stack leaving vars. Check for immediate '(' after a ')' is parsed.

int Solution::braces(string A) 
{
    stack<char> stk ;
    int size = A.size() ;
    int redud = 0 ;
    
    for( int i = 0 ; i < size && redud == 0 ; i++ )
    {
        bool in = false ;
        
        switch( A[i] )
        {
            case '(' :
            case '+' :
            case '-' :
            case '/' :
            case '*' :
            case '%' :  in = true ; break ;
        }
        
        if( in == true )
        {
            stk.push( A[i] ) ;
        }
        
        // If a digit or a closing brace is parsed.
        else
        {
            // If it is not a digit
            if( A[i] == ')' )
            {
                char c = stk.top() ;
                
                // If first top is opening braces, Redundant brace is present.
                if( c == '(' )
                    redud = 1 ;
                else
                {
                    // Pop till matching opening braces is found
                    while( c != '(' && !stk.empty() )
                    {
                        stk.pop() ;
                        c = stk.top() ;
                    }
                    stk.pop() ;
                }
            }
        }
        
    }
    
    return redud ;
}
