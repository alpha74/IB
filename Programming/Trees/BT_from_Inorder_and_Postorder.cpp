// Almost same as using Preorder.
// Diff:
// Traverse Postorder from reverse.
// Create right subtree first, then left sub tree.
// Start curr from reverse on postorder.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *consT( vector<int> &pos, map<int,int> &index, int start, int end, int &curr ) 
{
	if( start > end ) 
		return NULL ;
		
	// If single node
	else if( start == end )
	{
		TreeNode *root = new TreeNode( pos[curr] ) ;
		curr-- ;
		return root ;
	}
	else
	{
		TreeNode *root = new TreeNode( pos[ curr ] ) ;
		
		// Get index of pos[curr] from map of inorder
		auto iter = index.find( pos[curr] ) ;
		
		int m = iter -> second ;
		curr-- ;
		// Recursive call : right and left
		root -> right = consT( pos, index, m+1, end, curr ) ;
		root -> left = consT( pos, index, start, m-1, curr ) ;
		
		
		return root ;
	}
	
} 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    map<int,int> index ;
    
    for( int i = 0 ; i < A.size() ; i++ )
    {
        index.insert( pair<int,int>( A[i], i)) ;
    }
    
    int curr = B.size() -1 ;
 
    // Construct the Tree   
    TreeNode *root = consT( B, index, 0, B.size() -1, curr ) ;    
    
    return root ;
}
