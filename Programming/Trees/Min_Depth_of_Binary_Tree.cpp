// Use a variable as a reference, and keep updating the min value when leaf is found.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void minheight( TreeNode* A, int h, int &allmin )
{
	if( A == NULL )
	{
	    return ;
	}
	else if( A -> left == NULL && A -> right == NULL )
	{
	    allmin = min( allmin, h + 1 ) ;
	    return ;
	}
	h++ ;
	
	minheight( A -> left, h, allmin ) ;
	minheight( A -> right, h, allmin ) ;
	
}  
 
 
int Solution::minDepth(TreeNode* A) 
{
    int allmin = INT_MAX ;
    
    minheight( A, 0, allmin ) ;

    
    return allmin ;
}
