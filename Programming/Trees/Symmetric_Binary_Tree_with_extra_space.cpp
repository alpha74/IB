// Store inorder traversal.
// Array should be odd. Check if palindrome exists(see code).

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
 

 
int Solution::isSymmetric(TreeNode* A) 
{
    vector<int> inod ;
    
    // Get inorder traversal of tree    
    inorder( A, inod ) ;
    
    int ret = 0 ;
    
    if( inod.size() % 2 == 0 )
        ret = 0 ;
    else
    {
        int i = inod.size() / 2 ;
        int j = i+1 ;
        i-- ;
        
        ret = 1 ;
        
        while( i >= 0 && j < inod.size() && ret == 1 )
        {
            if( inod[i] != inod[j] )
                ret = 0 ;
            
            i-- ;
            j++ ;
        }
    }
    
    return ret ;
}
