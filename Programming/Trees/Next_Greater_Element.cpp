// Simple tree traversal trick.
// Uses O(1) space.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) 
{
    TreeNode *ret = NULL ;
    
    while( A != NULL )
    {
        if( A -> val > B )
        {
            ret = A ;
            A = A -> left ;
        }
        else
        {   
            A = A -> right;
        }
    }
    
    return ret ;
}
