// Start with a range of values that is valid.
// For each node, limit the value according to left or right sub-trre, recursively.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool validBST( TreeNode *A, int l, int h )
{
	if( A == NULL )
		return true ;

	if( A -> val >= h || A -> val <= l )
		return false ;
	
  // Left sub-tree
	bool ret = validBST( A -> left, l, A -> val ) ;
	
  // Right sub-tree
	if( ret == true ) 	
		ret = validBST( A -> right, A -> val, h ) ;
		
	return ret ;	
}
 
int Solution::isValidBST(TreeNode* A) 
{
    if( validBST( A, INT_MIN, INT_MAX ) == true )
        return 1 ;
    else
        return 0 ;
}
