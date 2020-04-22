// Check three conditions: 1. lh and rh of current node 2. left subtree 3. right subtree

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
    
    return 1+ max( maxheight( root -> left ), maxheight( root -> right ) ) ;
}  
 
bool is_bal( TreeNode *A  )
{
    if( A == NULL )
        return true ;
    
    int l = maxheight( A -> left ) ;
    int r = maxheight( A -> right ) ;

    if( abs( l - r ) <= 1 && is_bal( A -> left ) == true && is_bal( A -> right ) == true )
        return true ;
    
    return false ;
}


 
int Solution::isBalanced(TreeNode* A) 
{
    
    bool b = is_bal( A ) ;
    
    if( b == true )
        return 1 ;
    else
        return 0 ;
}
