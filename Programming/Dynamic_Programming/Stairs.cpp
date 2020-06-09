// Use recursive approach in calculating ways.
// Use extra space to store already computed values.

map<int,int> ways ;

int steps( int rem )
{
    if( rem < 0 )
        return 0;
    
    else if( rem == 1 )
        return 1 ;
    
    else if( rem == 2 )
        return 2 ;
    
    else
    {
        auto iter = ways.find( rem ) ;
        
        if( iter != ways.end() )
            return iter -> second ;
        
        // else
        // We can take 1 step or 2 step.
        int ret = steps( rem-2 ) + steps( rem-1 ) ;
        
        ways[ rem ] = ret ;
        return ret ;       
    }
}

int Solution::climbStairs(int A) 
{
    return steps( A ) ;
}
