// Store Tree nodes in a vector in preorder traversal.
// Connect the right nodes and make left nodes NULL.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preorder( TreeNode *A, vector<TreeNode*> &arr )
{
    if( A == NULL )
        return ;
        
    else
    {
        arr.push_back( A ) ;
        
        if( A -> left != NULL )
            preorder( A -> left, arr ) ;
        
        
        
        if( A -> right != NULL )
            preorder( A -> right, arr ) ;
    }
}
 
 
TreeNode* Solution::flatten(TreeNode* A) 
{
    vector<TreeNode*> list ;
    
    preorder( A, list ) ;
    
    TreeNode *head = new TreeNode(-1) ;
    TreeNode* temp = head ;
    
    for( int i = 0 ; i < list.size() ; i++ )
    {
        head -> right = list[i] ;
        head = head -> right ;
        head -> left = NULL ;
    }
    
    list.clear() ;
    head = temp -> right ;
    delete temp ;
    
    return head ;
}


