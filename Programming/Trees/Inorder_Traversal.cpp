// Simple Inorder Traversal

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder( TreeNode *A, vector<int> &arr )
{
    if( A == NULL )
        return ;
        
    else
    {
        if( A -> left != NULL )
            inorder( A -> left, arr ) ;
        arr.push_back( A -> val ) ;
        
        if( A -> right != NULL )
            inorder( A -> right, arr ) ;
    }
}
 
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    vector<int> ret ;
    
    inorder( A, ret ) ;
    
    return ret ;
}
