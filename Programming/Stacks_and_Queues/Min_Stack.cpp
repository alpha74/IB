// Using stack of pairs of int
// Maintain min value as second value at each element.

stack< pair<int,int> > stk ;


MinStack::MinStack() 
{
    while( !stk.empty() )
        stk.pop() ;
}

void MinStack::push(int x) 
{
    int min_num = x ;
    
    if( !stk.empty() )
        min_num = min( stk.top().second, x ) ;
        
    stk.push( make_pair( x, min_num )) ;
}

void MinStack::pop() 
{
    if( !stk.empty() )
        stk.pop() ;
}

int MinStack::top() 
{
      if( stk.empty() )
        return -1 ;
        
    else
    {
        int num = stk.top().first ;
        
        return num ;
    }
}

int MinStack::getMin() 
{
    if( stk.empty() )
        return -1 ;
        
    else
    {
        int min_elem = stk.top().second ;
        
        return min_elem ;
    }
}

