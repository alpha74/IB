// 1. Create a map of good words by forming individual strings
// 2. Calculate scores for each review string
// 3. Sort the scores in another array, to get required position indices
// 4. Return result

// To sort in descending order
bool desc( int a, int b )
{
    if( a > b )
        return true ;
    return false ;
}

vector<int> Solution::solve(string A, vector<string> &B) 
{
    map<string,bool> gwords ;
    
    // 1. Create a map of good words by forming individual strings
    string gw = "" ;
    for( int i = 0 ; i < A.length() ; i++ )
    {
        if( A[i] == '_' )
        {
            gwords.insert( pair<string,bool>( gw, false )) ;
            gw = "" ;
        }
        else
            gw = gw + A[i] ;
    }
    gwords.insert( pair<string,bool>( gw, false ) ) ;
    
    
    gw = "" ;
    vector<int> scores ;
    
    // 2. Calculate scores for each review string
    
    // For each string of reviews
    for( int i = 0 ; i < B.size() ; i++ )
    {
        int score = 0 ;
        gw = "" ;
        
        // For each word in a review check if it is a good word
        for( int j = 0 ; j < B[i].length() ; j++ )
        {
            if( B[i][j] == '_' )
            {
                auto iter = gwords.find( gw ) ;
                
                if( iter != gwords.end() )
                    score++ ;
                
                gw = "" ;
            }
            else
                gw = gw + B[i][j] ;
        }
        auto iter = gwords.find( gw ) ;
                
        if( iter != gwords.end() )
            score++ ;
        
        scores.push_back( score ) ;
    }
    
    // 3. Sort the scores in another array, to get required position indices
    vector<int> tscores = scores ;
    sort( tscores.begin(), tscores.end(), desc ) ;
    
    vector<int> ret ;
    
    for( int i = 0 ; i < tscores.size() ; i++ )
    {
        // Find first element in scores
        int index = -1 ;
        for( int j = 0 ; j < scores.size() && index == -1 ; j++ )
        {
            if( scores[j] == tscores[i] )
            {
                index = j ;
                scores[index] = -1 ;
            }
        }
        
        ret.push_back( index ) ;
    }
    
    // Return result
    return ret ;
}
