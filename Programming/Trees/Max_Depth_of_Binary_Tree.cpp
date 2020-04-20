// Simple recursive approach.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxheight( TreeNode* root )
{
    if( root == NULL )
        return 0 ;
    
    return max(1 + maxheight( root -> left ), 1 + maxheight( root -> right ) ) ;
} 

int Solution::maxDepth(TreeNode* A) 
{
   
    return maxheight( A ) ; 
}
