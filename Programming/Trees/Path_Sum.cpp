// Keep track of sum from root to leaf. Compare path sum when at leaf node.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void pathsum( TreeNode *A, int &k, bool &has, int curr )
{
	if( A == NULL )
	{
		return ;
	}
	else if( A-> left == NULL && A -> right == NULL )
	{
		curr = curr + A -> val ;
		if( curr == k )
			has = has | 1 ;
	}
	else
	{
		curr = curr + A -> val ;
		pathsum( A -> left, k, has, curr ) ;
		pathsum( A -> right, k, has, curr ) ;
	}
}

int Solution::hasPathSum(TreeNode* A, int B) 
{
	bool has = 0 ;
	
	pathsum( A, B, has, 0 ) ;
	
	return has ;
}

 
