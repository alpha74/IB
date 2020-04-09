// Create a new Number Format with base 3.
// Increment this number and get new combination. Map the appropriate char using offset.

class Position
{
    public: 
    string postr ;
    
    Position()
    {
        postr = "" ;
    }
    Position( int n )
    {
        postr = "" ;
        
        for( int i = 0 ; i < n ; i++ )
            postr = postr + '0' ;
    }
    void increment( map<char,char> &len, string &str )
    {
        int i = 0 ;
        bool carry = false ;
        
        int last = postr.length() -1 ;
        auto iter = len.find( str[ last ] ) ;
        
        postr[ last ] = postr[ last ] + 1 ;
        
        if( postr[ last ] >= ( iter -> second ) )
            carry = true ;
        else
            carry = false ;
        
        // If carry is true, increment last-1 and check for carry again
        while( carry == true && last >= 0 )
        {
            carry = false ;
            postr[ last ] = '0' ;
            last-- ;
            
            auto iter = len.find( str[ last ] ) ;
            postr[ last ]++ ;
            
            if( postr[ last ] >= iter -> second )
            {
                carry = true ;                    
            }
        }
    }
    
    bool operator!= ( Position comp )
    {
        bool ret = true ;
        
        for( int i = 0 ; i < comp.postr.length() && ret == true ; i++ )
        {
            if( comp.postr[i] != postr[i] )
                ret = false ;
        }
        
        return !ret ;
    }
} ;

// Returns char associated with digit using offset
char return_char( char a, int offset )
{
    char ret = '#' ;
    
    char arr2[] = { 'a', 'b', 'c' } ;
    char arr3[] = { 'd', 'e', 'f' } ;
    char arr4[] = { 'g', 'h', 'i' } ;
    char arr5[] = { 'j', 'k', 'l' } ;
    char arr6[] = { 'm', 'n', 'o' } ;
    char arr7[] = { 'p', 'q', 'r', 's' } ;
    char arr8[] = { 't', 'u', 'v' } ;
    char arr9[] = { 'w', 'x', 'y', 'z' } ;
    
    switch( a )
    {
        case '0' : ret = '0' ;  break ;
        case '1' : ret = '1' ;  break ;
        
        case '2' :  
                    if( offset > 2 )
                        offset = 2 ;
                    ret = arr2[0+offset] ;
                    break ;
        
        case '3' :  
                    if( offset > 2 )
                        offset = 2 ;
                    ret = arr3[0+offset] ;
                    break ;
        
        case '4' :  
                    if( offset > 2 )
                        offset = 2 ;
                    ret = arr4[0+offset] ;
                    break ;
                    
        case '5' :  
                    if( offset > 2 )
                        offset = 2 ;
                    ret = arr5[0+offset] ;
                    break ;
                    
        case '6' :  
                    if( offset > 2 )
                        offset = 2 ;
                    ret = arr6[0+offset] ;
                    break ;
        
        case '7' :  
                    if( offset > 3 )
                        offset = 3 ;
                    ret = arr7[0+offset] ;
                    break ;
                    
        case '8' :  
                    if( offset > 2 )
                        offset = 2 ;
                    ret = arr8[0+offset] ;
                    break ;
                    
        case '9' :  
                    if( offset > 3 )
                        offset = 3 ;
                    ret = arr9[0+offset] ;
                    break ;
    }
    
    return ret ;
}

vector<string> Solution::letterCombinations(string A) 
{
    map<char,char> len ;
    
    // Set number of values associated with digits
    len.insert( pair<char,int>( '1', '1' ) ) ;
    len.insert( pair<char,int>( '2', '3' ) ) ;
    len.insert( pair<char,int>( '3', '3' ) ) ;
    len.insert( pair<char,int>( '4', '3' ) ) ;
    len.insert( pair<char,int>( '5', '3' ) ) ;
    len.insert( pair<char,int>( '6', '3' ) ) ;
    len.insert( pair<char,int>( '7', '4' ) ) ;
    len.insert( pair<char,int>( '8', '3' ) ) ;
    len.insert( pair<char,int>( '9', '4' ) ) ;
    len.insert( pair<char,int>( '0', '1' ) ) ;
    
    vector<string> ret ;
    
    Position comb( A.length() ) ;
    Position comb0( A.length() ) ;
    Position comblast( A.length() ) ;
    
    comb.increment( len, A ) ;
    
    while( comb != comb0  )
    {
        string newcomb = "" ;
        
        for( int i = 0 ; i < A.length() ; i++ )
        {
            newcomb = newcomb + return_char( A[i], comblast.postr[i] - 48 ) ;
        }
        
        ret.push_back( newcomb ) ;
        
        comblast = comb ;
        comb.increment( len, A ) ;
    }
    string newcomb = "" ;
    for( int i = 0 ; i < A.length() ; i++ )
    {
        newcomb = newcomb + return_char( A[i], comblast.postr[i] -48 ) ;
    }
    ret.push_back( newcomb ) ;
   
    sort( ret.begin(), ret.end() ) ;
    
    return ret ;
}
