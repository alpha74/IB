// Create Trie on each string.
// Find prefix from Trie then.

class TrieNode
{
    public:
        char c ;
        TrieNode *chars[26] ;
        bool unique ;
    
        TrieNode()
        {
            c = '-' ;
            unique = true ;
            // Initialize to NULL pointers
            for( int i = 0 ; i < 26 ; i++ )
                chars[i] = NULL ;
        }
} ;

void createTrie( TrieNode *root, string s )
{
    TrieNode *curr = root ;
    
    for( int i = 0 ; i < s.length() ; i++ )
    {
        int ch = s[i] - 97 ;
        
        // Create new node
        if( curr -> chars[ch] == NULL )
        {
            TrieNode *newnode = new TrieNode() ;
            newnode -> c = s[i] ;
            curr -> chars[ch] = newnode ;
            
            curr = curr -> chars[ch] ;
        }
        else
        {
            curr = curr -> chars[ch] ;
            curr -> unique = false ;
        }
    }
    
}

string getPrefix( TrieNode *root, string s  )
{
    string pref ;
    
    bool stop = false ;
    
    for( int i = 0 ; i < s.length() && stop == false ; i++ )
    {
        root = root -> chars[ s[i]-97 ] ;
        pref = pref + root -> c ;
        
        if( root -> unique == true )
            stop = true ;
    }
    
    return pref ;
}

vector<string> Solution::prefix(vector<string> &A) 
{
    TrieNode *root = new TrieNode() ;
    root -> unique = false ;
    
    // Create Trie from strings
    for( int i = 0 ; i < A.size() ; i++ )
    {
        createTrie( root, A[i] ) ;
    }
    
    vector<string> ret ;
    // Ger prefix from trie
    for( int i = 0 ; i < A.size() ; i++ )
    {
        ret.push_back( getPrefix( root, A[i]) ) ;
    }
    
    return ret ;
}
