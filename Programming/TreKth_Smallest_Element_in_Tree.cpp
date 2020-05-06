// k is B
// Decrement B in V of inorder traversal(LVR).
// Store val when B==0

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder( TreeNode* A, int &B, int &val )
{
    if( A == NULL )
        return ;
    
    inorder( A -> left, B, val ) ;
    
    B-- ;
    if( B == 0 )
    {
        val = A -> val ;
        return ;
    }
    
    inorder( A -> right, B, val ) ;
    
}
 
int Solution::kthsmallest(TreeNode* A, int B) 
{
    int val = -1 ;
    inorder( A, B, val ) ;
    
    return val ;
}
