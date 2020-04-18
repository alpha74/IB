// Recursively see node val.
// Call same for left and right sub-trees.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool sameBT( TreeNode* A, TreeNode *B )
{
    if( A == NULL && B == NULL )
        return true ;
    
    // If one is NULL
    else if( ( A == NULL && B != NULL ) || ( A != NULL && B == NULL ) )
        return false ;
    
    // If both are not NULL    
    else
    {
        if( A -> val != B -> val )
            return false ;
        
        bool ret = sameBT( A -> left, B -> left ) ;
        
        if( ret == true )
            ret = sameBT( A -> right, B -> right ) ;
            
        return ret ;    
    }
}
 
int Solution::isSameTree(TreeNode* A, TreeNode* B) 
{
    return sameBT( A, B ) ;
        
}
