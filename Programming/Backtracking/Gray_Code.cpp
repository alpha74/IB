// Start from list [0,1]
// Follow steps in comments .
// Solution is built from start bits.

vector<int> Solution::grayCode(int A) 
{
	
	vector< vector<int> > list1, list2 ;
	
	vector<int> bit0, bit1 ;
	
	// Start with bits 0 and 1
	bit0.push_back( 0 ) ;
	bit1.push_back( 1 ) ;
	
	list1.push_back( bit0 ) ;
	list1.push_back( bit1 ) ;
	
	/*
	    - Notation :
	        - list1 : [ [0], [1] ]
	        
	        list2 is reverse of list1
	        - list2 : [ [1], [0] ]
	        
	    - Return list of int after combining individual lists in list1(base2 to base10)
	    - Eg:   list1 : [ [0,0], [0,1], [1,1], [1,0] ]
	            Returned list: [ 0, 1, 3, 2 ]
	*/
	
	for( int i = 1 ; i < A ; i++ )
	{
		// Create a copy of list1
		list2 = list1 ;
		
		// Reverse the list
		reverse( list2.begin(), list2.end() ) ;
		
		// Prepend 0s to all elements in list1
		for( int j = 0 ; j < list1.size() ; j++ )
		{
			list1[ j ].insert( list1[j].begin(), 0 ) ;
		}
		
		// Prepend 1s in list2
 		for( int j = 0 ; j < list2.size() ; j++ )
 		{
 			list2[ j ].insert( list2[j].begin(), 1 ) ;	
		}
		
		// Appends list2 in list1
		for( int j = 0 ; j < list2.size() ; j++ )
		{
			list1.push_back( list2[j] ) ;
		}
	}
	
	// Generate numbers in decimal format from binary format
	vector<int> ret ;
	
	for( int i = 0 ; i < list1.size() ; i++ )
	{
		int num = 0 ;
		
		// Generate number from power of 2 method
		for( int j = list1[i].size() -1, k = 0 ; j >= 0 ; j--, k++  )
		{
			num = num + pow( 2, k ) * list1[ i ][ j ] ;
		}
		
		ret.push_back( num ) ;
	}
	
	return ret ;
}
