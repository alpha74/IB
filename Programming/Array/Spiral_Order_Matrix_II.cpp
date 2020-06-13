// See comments in getSpiral()

void getSpiral( vector<vector<int>> &arr, int n )
{
	int i = 0 ;
	
	int row = 0, col = 0 ;	// row: starting index of row;  col : starting index of col
	int m = n, val = 1 ; 	// m rows and n cols
  
  	// Traverse the array in clockwise-spiral and set the val
    while ( row < m && col < n ) 
	{ 
        // Last of remaining rows : Left to right
        for ( i = col ; i < n; i++ )
			  arr[ row ][i] = val++ ;
        
        row++; 
  
        // Last of remaining columns : Top to bottom
        for ( i = row ; i < m ; i++ )
        	arr[ i ][ n-1 ] = val++ ; 
            
        n--; 
  
        // Last row from remaining rows : Right to left
        if ( row < m ) 
		{ 
            for ( i = n - 1; i >= col ; i-- ) 
				arr[ m-1 ][ i ] = val++ ;
                
            m--; 
        } 
  
        // First of remaining columns : Bottom to top
        if ( col < n ) 
		{ 
            for ( i = m - 1; i >= row ; i-- )
            	arr[ i ][ col ] = val++ ; 
                
            col++ ;
        } 
    }
}


vector<vector<int> > Solution::generateMatrix(int A) 
{
    // Create a AxA matrix
    vector<vector<int>> arr( A, vector<int> ( A, 0 ) ) ;
    
    // Call function to fill the array
    getSpiral( arr, A ) ;
    
    return arr ;
}
