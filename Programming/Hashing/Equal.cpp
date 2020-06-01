// Question is simple IF: all elements are unique.
// Here, duplicates are also present.
/*
  Solved in 2 parts: loop1 and loop2.

  Use map of (sum, list_of_pairs )
  => Size of list_pairs should not exceed 2.
  => First loop adds pair sums, and adds entry in sumhash. Check IF conditions here. Size of list pairs should not exceed 2.
  
  => Loop 2 extracts all pairs from sumhash if number of pairs in list_pairs if == 2(then only A+B=C+D is true for pair(A,B) and pair(C,D).
  => Each newrow is compared with minp array, which is initially largest. 
  => Compare and keep track of smallest minp. minp is the answer.
  => NOTE: If lexicographic result was not needed, we could have skipped loop2
*/

vector<int> Solution::equal(vector<int> &A) 
{
    // Sum and pair of elements
    map<int, vector<pair<int,int>>> sumhash ;
    int size = A.size() ;
    
      
    // Loop 1 : O(n^2)
    for( int i = 0 ; i < size ; i++ )
    {
        for( int j = i+1 ; j < size ; j++ )
        {
            // Compute (A+B)
            int lsum = A[i] + A[j] ;
            
            // Check if this sum is present in sumhash
            auto iter = sumhash.find( lsum ) ;
            
            // This sum is encountered first time: save it
            if( iter == sumhash.end() )
            {
            	vector<pair<int,int>> newrow ;
            	newrow.push_back( make_pair( i, j ) ) ;
            
            	sumhash[ lsum ] = newrow ;
			      }
            
            // Some other pair exists with same sum
            else
            {                
                pair<int,int> newpair ;
                newpair.first = i ;
                newpair.second = j ;
                
                vector<pair<int,int>> curr = iter -> second ;
                
                // Check this and next condition(they are split for better visibility). Go ahead only if all 4 elements are unique.
                if( newpair.first != curr[0].first && newpair.first != curr[0].second )
                {
					      if( newpair.second != curr[0].first && newpair.second != curr[0].second )
		           	{	// Add new pair
		                curr.push_back( newpair ) ;
		                
		                // Only two entries should remain in it
		                if( curr.size() > 2 )
		                {
		                	sort( curr.begin(), curr.end() ) ;
		                	curr.erase( curr.begin() + 2, curr.end() ) ;
					}
					}
				}
	                
                // Store the array again
                iter -> second = curr ;
            }
        }
    }
  
    // Result array
    vector<int> minp ;
    minp.push_back( INT_MAX ) ;
    minp.push_back( INT_MAX ) ;
    minp.push_back( INT_MAX ) ;
    minp.push_back( INT_MAX ) ;
    
    auto iter = sumhash.begin() ;
    // Loop 2
    // Get minimum entry
    for( ; iter != sumhash.end() ; iter++ )
    {
    	vector<pair<int,int>> curr = iter -> second ;
    	
    	if( curr.size() == 2 )
    	{
    		vector<int> newrow ;
    		
    		newrow.push_back( curr[0].first ) ;
    		newrow.push_back( curr[0].second ) ;
    		newrow.push_back( curr[1].first ) ;
    		newrow.push_back( curr[1].second ) ;
    		
    		if( newrow < minp )
          minp = newrow ;
		}
	}
    
   return minp ;
}
