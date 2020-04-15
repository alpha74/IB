// Uses Inorder traversal. O(n) extra space.
// Store inorder traversal of TreeNodes in an array. Return Node having val > B .


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder( TreeNode *A, vector<TreeNode *> &arr )
{
    if( A == NULL )
        return ;
        
    else
    {
        if( A -> left != NULL )
            inorder( A -> left, arr ) ;
            
        arr.push_back( A ) ;
        
        if( A -> right != NULL )
            inorder( A -> right, arr ) ;
    }
} 
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) 
{
    vector<TreeNode *> arr ;
    
    inorder( A, arr ) ;
    
    int index = -1 ;
    
    for( int i = 0 ; i < arr.size() && index == -1 ; i++ )
    {
        
        if( arr[i] -> val == B )
        {
            index = i ;
        }
    }
    
    if( index == -1 || index == ( arr.size() -1 ) ) 
        return NULL ;
    else
    {
        return arr[index+1] ;
    }
    
}
