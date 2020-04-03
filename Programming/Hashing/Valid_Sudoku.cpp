// Use hash to check for correctness of all 3 conditions of Sudoku.

// Check squares of 9x9
bool check_squares( const vector<string> &A, const int &size )
{
    map<char,bool> present ;
    bool ret = true ;
    
    for( int i = 0 ; i < size && ret == true ; i+= 3 )
    {
        for( int j = 0 ; j < size && ret == true ; j += 3 )
        {
            present.clear() ;
            
            for( int p = i ; p < (i+3) && ret == true ; p++ )
            {
                for( int q = j ; q < (j+3) && ret == true ; q++ )
                {
                    if( A[p][q] != '.' )
                    {
                        auto iter = present.find( A[p][q] ) ;
                        
                        if( iter == present.end() )
                            present.insert( pair<char, bool>( A[p][q], true ) ) ;
                        else
                            ret = false ;
                    }
                }
            }
        }
        
    }
    
    return ret ;
}

int Solution::isValidSudoku(const vector<string> &A) 
{
    bool ret = true ;
    int size = 9 ;
    
    map<char,bool> present ;
    
    // Check rows
    for( int i = 0 ; i < size && ret == true ; i++ )
    {
        present.clear() ;
        for( int j = 0 ; j < size && ret == true ; j++ )
        {
            if( A[i][j] != '.' )
            {
                auto iter = present.find( A[i][j] ) ;
                
                if( iter == present.end() )
                    present.insert( pair<char,bool>(A[i][j], true ) );
                else
                    ret = false ;
            }
        }
    }
    
    if( ret == false )
        return 0 ;
    
    // Check columns
    for( int i = 0 ; i < size && ret == true ; i++ )
    {
        present.clear() ;
        for( int j = 0 ; j < size && ret == true ; j++ )
        {
            if( A[j][i] != '.' )
            {
                auto iter = present.find( A[j][i] ) ;
                
                if( iter == present.end() )
                    present.insert( pair<char,bool>(A[j][i], true ) );
                else
                    ret = false ;
            }
        }
    }
    
    if( ret == false )
        return 0 ;
        
    // Check squares
    ret = check_squares( A, size ) ;
    
    return (ret == true)? 1 : 0 ;
}
