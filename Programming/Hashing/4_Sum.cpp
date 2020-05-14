// Sort the array.
// Use two nested loops: i and j.
// Use two pointer approach in third nested loop.
// Use hash for storing the unique quad array.

// TLE : When duplicates are not skipped in third nested loop.

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) 
{
    int size = A.size() ;
    
    vector<vector<int>> ret ;
    map< vector<int>, bool > uniq ;
    
    if( size < 4 )
        return ret ;
    
    // Sort the array    
    sort( A.begin(), A.end() ) ;
    
    for( int i = 0 ; i < size -3 ; i++ )
    {
        for( int j = i + 1 ; j < size -2 ; j++ )
        {
            int p = j + 1 ;
            int q = size -1 ;
            
            while( p < q )
            {
                int sum = A[i] + A[j] + A[p] + A[q] ;
                
                if( sum == B )
                {
                    // Create new quad array
                    vector<int> row ;
                    
                    row.push_back( A[i] ) ;
                    row.push_back( A[j] ) ;
                    row.push_back( A[p] ) ;
                    row.push_back( A[q] ) ;
                
                    
                    // Check if it already exists
                    auto iter = uniq.find( row ) ;
                    
                    if( iter == uniq.end() )
                    {
                        ret.push_back( row ) ;
                        uniq.insert( pair<vector<int>, bool>( row, false ) ) ;
                    }
                   
                    
                    int pval = A[p] ;
                    // Iterate over duplicates at p
                    while( p + 1 < size && A[p] == pval )
                        p++ ;
                        
                    int qval = A[q] ;    
                    // Iterate over duplicates at q
                    while( q > p  && A[q] == qval )
                        q-- ;
     
                }
                else if( sum > B )
                {
                    q-- ;
                }
                else
                {
                    p++ ;
                }
            }
        
        }
    
    }
    
    return ret ;
}
