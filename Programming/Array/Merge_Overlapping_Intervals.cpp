// Compare first with next.
// See comments

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool sortPair(const Interval& a, const Interval& b)
{
    return (a.start < b.start);
}

vector<Interval> Solution::merge(vector<Interval> &A)
{
	// If only one interval is present 
    if( A.size() < 2 ) 
	{
        return A ;
    }
    
    int size = A.size() ;
    // Sort the pair on: start
    sort( A.begin(), A.end(), sortPair ) ;
    
    int first = 0 ;
    
    for( int second = 1; second < size ; second++ )  
	{
        // If start of second is <= end of first : overlapping -> merge both
        if( A[ second ].start <= A[ first ].end ) 
		{
            A[ first ].end = max( A[ second].end, A[first].end ) ;
        }
        
        // No overlap between current first and second
        else 
		{
			first++ ;
			
			// 
            A[ first ].start = A[ second ].start ;
            A[ first ].end = A[ second ].end ;
        }
    }
    
    // Remove the leftover pairs(which can be left after merging )
    A.erase( A.begin() + first + 1, A.end() ) ;
    
	return A ;
}
