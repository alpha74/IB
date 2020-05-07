// Do postorder traversal.
// On coming back, swap the left and right subtrees.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void invertBT( TreeNode* A )
{
    if( A == NULL )
        return ;
    
    invertBT( A -> left ) ;
    invertBT( A -> right ) ;
    
    TreeNode *temp = A -> left ;
    A -> left = A -> right ;
    A -> right = temp ;
    
    return ;
}
 
TreeNode* Solution::invertTree(TreeNode* A) 
{
    invertBT( A ) ;
    return A ;
}
