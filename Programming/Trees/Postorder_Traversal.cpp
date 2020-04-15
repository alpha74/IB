// Simple recursive approach for postorder traversal.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void postorder( TreeNode *A, vector<int> &arr )
{
    if( A == NULL )
        return ;
    else
    {
        postorder( A -> left, arr ) ;
        postorder( A -> right, arr ) ;
        arr.push_back( A -> val ) ;
    }
}
 
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    vector<int> ret ;
    
    postorder( A, ret ) ;
    
    return ret ;
}
