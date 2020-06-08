// Get maxjummp possible from curr index.
// Reset curr index and curr max jump and reiterate.
// See comments

int minJumps( vector<int> &A )
{
    int size = A.size() ;
    
    if( A[0] == 0 && size == 1 )
        return 0 ;
    
    if( A[0] == 0 && size > 1 )
        return -1 ;
    
    // If using I element, we can reach to end, 1 jump is needed
    else if( A[0] >= size-1 )    
        return 1 ;
    
    
    int fuel = A[0];
    int i = 0, jumps = 1 ;
    
    while( fuel != 0 )
    {
        // If end is reachable, return ans.
        if( i + fuel >= size-1 )
            return jumps ;
        
        else
        {
            int currfuel = fuel ;
            int maxjumprange = 0, newfuel = 0, newi = i ;
            
            while( currfuel-- )
            {
                i++ ;
                
                // Get maximum jump possible
                if( maxjumprange <= i + A[i] )
                {
                    maxjumprange = i + A[i] ;
                    newfuel = A[i] ;
                    newi = i ;
                }
            }
            i = newi ;
            fuel = newfuel ;
        }
        jumps++;
    }
    
    // If first element is 0
    return -1;
}

int Solution::jump(vector<int> &A) 
{
    return minJumps( A ) ;
}
