/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void preorder( TreeNode *A, vector<int> &arr )
{
    if( A == NULL )
        return ;
        
    else
    {
        arr.push_back( A -> val ) ;
        
        if( A -> left != NULL )
            preorder( A -> left, arr ) ;
        
        
        
        if( A -> right != NULL )
            preorder( A -> right, arr ) ;
    }
}
 

 
vector<int> Solution::preorderTraversal(TreeNode* A)
{
    vector<int> ret ;
    
    preorder( A, ret ) ;
    
    return ret ;
}
