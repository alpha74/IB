// Choose middle element and make it root. Do recusively for left and right sub-tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *array_to_bst( const vector<int> &A, int start, int end )
{
    if( start > end )
        return NULL ;
        
    int mid = ( start + end ) / 2 ;
    
    // Create root node
    TreeNode *root = new TreeNode( A[mid] ) ;
    
    // Do recusively for left and right subtree
    root -> left = array_to_bst( A, start, mid -1 ) ;
    root -> right = array_to_bst( A, mid+1, end ) ;
    
    return root ;
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    return array_to_bst( A, 0, A.size() - 1 ) ;
}
