// Generate subsequences and store individual products in hash.

int get_prod( vector<int> &n )
{
    int prod = 1 ;
    int size = n.size() ;
    
    for( int i = 0 ; i < size ; i++ )
    {
        prod = prod * n[i] ;
    }
    
    return prod ;
}

int Solution::colorful(int A)
{
    vector<int> num ;
    
    while( A > 0 )
    {
        num.push_back( A % 10 ) ;
        A = A / 10 ;
    }
    
    int size = num.size() ;
    
    bool ans = true ;
    // 23
    
    map<int,bool> listprod ;
    
    for( int i = 1 ; i <= size && ans == true ; i++ )
    {
        
        for( int k = 0 ; ( k + i- 1 ) < size && ans == true ; k++ )
        {
            vector<int> part ;
            for( int j = 0 ; k+j < size && part.size() < i ; j++ )
            {
                part.push_back( num[k+j] ) ;
            }
            int currprod = get_prod( part ) ;
            
            
            
            auto iter = listprod.find( currprod ) ;
            
            if( iter == listprod.end() )
            	listprod.insert( pair<int,bool>( currprod, false ) ) ;
            else
            	ans = false ;
        }
        
    }
    
    return ans ;
}

