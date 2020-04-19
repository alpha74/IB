// Read Cartesian Tree.
// See function ctree() and maxindex().

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Returns index of max element
int maxindex( vector<int> &A, int start, int end )
{
    int m = start ;
    
    for( start = start + 1 ; start <= end ; start++ )
    {
        if( A[ start ] > A[m] )
            m = start ;
    }
    
    return m ;
}

TreeNode *ctree( vector<int> &A, int start, int end )
{
    if( start > end )
        return NULL ;
        
    int maxi = maxindex( A, start, end ) ;
    
    // Create new node
    TreeNode *root = new TreeNode( A[ maxi ] ) ;
    
    // If there is only 1 element in current array
    if( start == end )
        return root ;
    
    // Call recursively
    root -> left = ctree( A, start, maxi -1 ) ;
    root -> right = ctree( A, maxi +1, end ) ;
    
    return root ;
}
 
TreeNode* Solution::buildTree(vector<int> &A) 
{
    return ctree( A, 0, A.size() -1 ) ;
}
