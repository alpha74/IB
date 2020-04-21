// Store depths of all leaves, and return the min.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void minheight( TreeNode* A, int h, vector<int> &hs )
{
	if( A == NULL )
	{
		return ;
	}
	else if( A -> left == NULL && A -> right == NULL )
	{
		hs.push_back( h +1 ) ;
		return ;
	}
	
    minheight( A -> left, h +1, hs ) ;
    minheight( A -> right, h + 1, hs ) ;
}  
 
 
int Solution::minDepth(TreeNode* A) 
{
    vector<int> hs ;
    
    minheight( A, 0, hs ) ;
    
    int minh = INT_MAX ;
    
    
    for( int i = 0 ; i < hs.size() ; i++ )
    {    	
        if( hs[i] < minh )
            minh = hs[i] ;
    }
    
    return minh ;
 
}
