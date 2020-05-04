// Use <priority_queue> and get top element each time.
// Remove it and push its half.
// Using <set> will not work due to presence of duplicates.

#define MOD 1000000007
   
int Solution::nchoc(int A, vector<int> &B) 
{

    // Create set from B
    priority_queue<int> ch ;
    
    for( int i = 0 ; i < B.size() ; i++ )
        ch.push( B[i] ) ;
    
    long long int total = 0 ;
    
    while( A-- )
    {
        int val = ch.top() ;
        
        total = ( total + val % MOD ) % MOD ;
        
        val = ch.top() ;
        
        ch.pop() ;
        ch.push( val/2) ;
    }
    
    return total ;
}


