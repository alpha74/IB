// Use preorder traversal and connect nodes.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* flatten_util( TreeNode *A, TreeNode *head ) 
{
    if( A == NULL )
        return head ;
    else
    {
        TreeNode *left = A -> left ;
        TreeNode *right = A -> right ;
        
        // Preorder setup
        head -> right = A ;
        head = head -> right ;
        head -> left = NULL ;
        
        head = flatten_util( left, head ) ;
        
        
        head = flatten_util( right, head ) ;
        
        return head ;
    }
}
 
TreeNode* Solution::flatten(TreeNode* A) 
{
    TreeNode *head = new TreeNode(-1) ;
    
    TreeNode *temp = flatten_util( A, head ) ;
	temp -> right = NULL ;
	temp -> left = NULL ;
	
	temp = head ;
	head = head -> right ;
	delete temp ;

    return head ;
}

