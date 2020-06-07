// Recursive approach.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<TreeNode*> generateAllBST( int start, int end )
{
    vector<TreeNode*> list ;
    
    // Exit condition of recursion
    if( start > end )
    {
        list.push_back( NULL ) ;
    }
    
    for( int i = start ; i <= end ; i++ )
    {
        // Recurse for left and right subtrees
        vector<TreeNode*> lefttree = generateAllBST( start, i-1 ) ;
        vector<TreeNode*> righttree = generateAllBST( i+1, end ) ;
        
        for( int j = 0 ; j < lefttree.size() ; j++ )
        {
            TreeNode *leftnode = lefttree[j] ;
            for( int k = 0 ; k < righttree.size() ; k++ )
            {
                TreeNode * rightnode = righttree[k] ;
                TreeNode *root = new TreeNode(i) ;
                
                root -> left = leftnode ;
                root -> right = rightnode ;
                
                list.push_back( root ) ;
            }
        }
    }
    
    return list ;
}
 
vector<TreeNode*> Solution::generateTrees(int A) 
{
    if( A == 0 )
    {
        vector<TreeNode*> emp ;
        return emp ;
    }
    return generateAllBST(1,A) ;
}
