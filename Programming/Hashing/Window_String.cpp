// Little Tricky.
// Read all comments first to understand.

string Solution::minWindow(string A, string B) 
{
	string ret = "" ;
	int winstart = -1, minlen = INT_MAX ;
	
	int sizeA = A.length() ;
	int sizeB = B.length() ;
	
	// If B is larger than A, no window can exist
	if( sizeB > sizeA || sizeA == 0 )
		return ret ;
		
	// char and its count : of pattern
	map<char,int> tfreq ;
	
	// Make char:freq map of B
	for( int i = 0 ; i < sizeB ; i++ )
	{
		auto iter = tfreq.find( B[i] ) ;
		
		if( iter == tfreq.end() )
			tfreq.insert( pair<char,int>( B[i], 1 ) ) ;
		else
			iter -> second += 1 ;
	}
	
	// char-freq map of string A
	map<char,int> freq ;
	
	// Number of characters in A matched with B
	int match = 0 ;
	// Curr window starting index
	int wincurr = 0 ;
	
	for( int i = 0 ; i < sizeA ; i++ )
	{
	    // Increment freq of A[i]
	    auto iter = freq.find( A[i] ); 
	    
	    if( iter == freq.end() )
	        freq.insert( pair<char,int>( A[i], 1)) ;
	    else
	        freq[ A[i] ]++ ;
	        
	        
	   // Check if current char exists in pattern   
	   auto iter2 = tfreq.find( A[i] ) ;
	   
	   if( iter2 != tfreq.end() && freq[ A[i] ] <= iter2 -> second )
	    match++ ;
	    
	   // If match becomes same as sizeT, a window is found
	   if( match == sizeB )
	   {
	       // Try to shorten the window from starting from wincurr, using these conditions
	       // If freq of element at wincurr is > corresponding freq in tfreq, we can shorten the window.
	       // Also, if element at wincurr not occurs in T, we can shorten the window
	       while( freq[ A[wincurr] ] > tfreq[ A[ wincurr ] ] || tfreq[ A[wincurr] ] == 0 && wincurr <= i )
	       {
	           // Decrement the count of S[wincurr] in freq, if curr char exists in T. 
	           // We are removing its one occurence from window
	           if( freq[ A[wincurr] ] > tfreq[ A[ wincurr ] ] )
	        	freq[ A[wincurr] ]-- ; 
	            
	           wincurr++ ;
	       }
	       
	       // Update the min window len
	       if( ( i-wincurr + 1 ) < minlen )
	       {
	           winstart = wincurr ;
	           minlen = (i-wincurr+1 );
	       }
	   }
	   
	}
	
	// If windows exists
	if( winstart != -1 )
	{
	    // Fill the result string
	    for( int i = 1 ; i <= minlen ; i++ )
	        ret += A[ winstart + i - 1 ] ;
	}
	
	
	return ret ;
}

