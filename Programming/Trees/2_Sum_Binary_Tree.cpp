// Get sorted array from BT using inorder.
// Apply tow pointer approach to get sum pairs.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder( TreeNode* A, vector<int>&arr )
{
    if( A == NULL )
        return ;
    
    inorder( A -> left, arr ) ;
    arr.push_back( A -> val ) ;
    inorder( A-> right, arr ) ;
    
    return ;
}
 
int Solution::t2Sum(TreeNode* A, int B) 
{
    vector<int> arr ;
    
    inorder( A, arr );
    
    int start = 0, end = arr.size() -1 ;
    bool flag = 0 ;
    
    while( start < end && flag == 0 )
    {
        if( arr[start] + arr[end] == B )
            flag = 1 ;
        
        else if( arr[start] + arr[end] > B )
            end-- ;
        else
            start++ ;
    }
    
    return flag ;
}
