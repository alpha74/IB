// Same as Path Sum. Take an extra path array whcih stores current path.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void pathlist( TreeNode *A, int &k, int curr, vector<vector<int>> &ret, vector<int> path )
{
	if( A == NULL )
	{
		return ;
	}
	else if( A-> left == NULL && A -> right == NULL )
	{
	    path.push_back( A -> val ) ;
	    
		curr = curr + A -> val ;
		if( curr == k )
			ret.push_back( path ) ;
	}
	else
	{
	    path.push_back( A -> val ) ;
	    
		curr = curr + A -> val ;
		pathlist( A -> left, k, curr, ret, path ) ;
		pathlist( A -> right, k, curr, ret, path ) ;
	}
} 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>> ret ;
    vector<int> path ;
    
    pathlist( A, B, 0, ret, path ) ;
    
    return ret ;
}

