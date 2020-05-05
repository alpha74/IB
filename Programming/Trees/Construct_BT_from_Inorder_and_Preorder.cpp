// Use preorder and root making index.
// All elements to the left of an element in inorder are in left subtree with this element as root.
// See Code.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *consT( vector<int> &pre, map<int,int> &index, int start, int end, int &curr ) 
{
	if( start > end ) 
		return NULL ;
		
	// If single node
	else if( start == end )
	{
		TreeNode *root = new TreeNode( pre[curr] ) ;
		curr++ ;
		return root ;
	}
	else
	{
		TreeNode *root = new TreeNode( pre[ curr ] ) ;
		
		// Get index of prec[curr] from map of inorder
		auto iter = index.find( pre[curr] ) ;
		
		int m = iter -> second ;
		curr++ ;
		// Recursive call : left and right
		root -> left = consT( pre, index, start, m-1, curr ) ;
		root -> right = consT( pre, index, m+1, end, curr ) ;
		
		return root ;
	}
	
} 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    	map<int,int> index ;
    
   	for( int i = 0 ; i < B.size() ; i++ )
	{
		index.insert( pair<int,int>( B[i],i ) ) ;
	}
	
	int curr = 0 ;
	TreeNode * root = consT( A, index, 0, B.size() -1, curr ) ;

	return root ;
}
