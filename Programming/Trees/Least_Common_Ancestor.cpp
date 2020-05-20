// Check for case when one or both values are not present in tree.
// Follow comments.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Find if node exists
bool find( TreeNode* A, int val )
{
    if ( A == NULL )
        return false;
        
    if ( A -> val == val )
        return true;
        
    if ( ( A -> left && find( A -> left, val)) || (A -> right && find( A->right, val) ))
        return true;
        
    return false ;
}

TreeNode *lcaNode( TreeNode *A, int B, int C )
{
	// Return NULL if current node is NULL
	if( A == NULL )
		return NULL ;
	
	// If val at current node matchec any of val1, val2, return current node
	else if( A -> val == B || A -> val == C )
		return A ;

	// If above conditions are not true		
	else
	{
		// Recursively check left and right sub-trees
		TreeNode *left = lcaNode( A -> left, B, C ) ;
		TreeNode *right = lcaNode( A -> right, B, C ) ;
		
		
		// Return NULL if both are NULL : indicates none of sub-trees contains match
		if( left == NULL && right == NULL )
			return NULL ;
			
		// If left has match 
		else if( right == NULL )
			return left ;
			
		// If right has a match	
		else if( left == NULL )
			return right ;		
			
		// If both have a match	
		else
			return A ;
		
	}
} 
 
int Solution::lca(TreeNode* A, int B, int C)
{
    // Check if vals exists
    if ( find(A, B) == false || find(A, C) == false )
        return -1 ;
    
    
    TreeNode *ret = lcaNode( A, B, C ) ;
    
    if( ret == NULL )
        return -1 ;
    else
        return ret -> val ;
}
