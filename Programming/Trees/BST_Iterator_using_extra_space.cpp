// Since, we don't have access to class itself, make global variables for storing inorder traversal.
// Use trav_index and trav_size for returning in O(1) and comparing the Size.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> traverse ;
int trav_index = 0 ;
int trav_size = 0 ;

void inorder( TreeNode *A, vector<int> &traverse )
{
    if( A == NULL )
        return ;
    
    inorder( A -> left, traverse ) ;
    traverse.push_back( A -> val ) ;
    inorder( A -> right, traverse ) ;
    
    return ;
}

BSTIterator::BSTIterator(TreeNode *root) 
{
    // Construct vector of inorder
    traverse.clear() ;
    trav_index = 0 ;
    trav_size = 0 ;
    inorder( root, traverse ) ;
    
    trav_size = traverse.size() ;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    if( trav_index < trav_size )
        return true ;
    else
        return false ;
}

/** @return the next smallest number */
int BSTIterator::next() 
{
    trav_index++ ;
    return traverse[ trav_index-1 ] ;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
