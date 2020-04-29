// Maintain a current level sum. Add to totalsum when leaf node.
// Use % 1003 everywhere.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void sumNumbersPath( TreeNode *A, int currsum, int &totalsum )
{
    // If NULL
    if( A == NULL )
        return ;
    
    // If leaf node    
    else if( A -> left == NULL && A -> right == NULL )
    {
        currsum = ( currsum * 10 ) % 1003 + (A -> val) % 1003 ;
        currsum = currsum % 1003 ;
        totalsum = ( totalsum % 1003 + currsum ) ;
        totalsum = totalsum % 1003 ;
    }
    else
    {
        currsum = (currsum * 10) % 1003 + (A -> val) % 1003 ;
        currsum = currsum % 1003 ;
        
        if( A-> left != NULL )
            sumNumbersPath( A -> left, currsum , totalsum ) ;
        
        if( A -> right != NULL )
            sumNumbersPath( A -> right, currsum, totalsum ) ;
    }
    
    return ;
}
 
int Solution::sumNumbers(TreeNode* A) 
{
    int totalsum = 0 ;
    
    sumNumbersPath( A, 0, totalsum ) ;
    
    //cout << "\n Sum: " << totalsum ;
    
    return totalsum % 1003 ;
}
