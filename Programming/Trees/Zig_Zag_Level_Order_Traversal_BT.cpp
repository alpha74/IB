// Use two stacks. See the order in which child nodes in pushed (opposite in both).

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A)
{
	stack<TreeNode*> stk1 ;
	stack<TreeNode*> stk2 ;
	
	vector<vector<int>> ret ;
	
	vector<int> row ;
	
	stk1.push( A ) ;

	
	while( !stk1.empty() || !stk2.empty() ) 
	{
		row.clear() ;
		
		while( !stk1.empty() )
		{
			// row.push_back( stk1.top() -> val ) ;
			
			row.push_back( stk1.top() -> val ) ;
		
			
			if( stk1.top() -> left != NULL )
				stk2.push( stk1.top() -> left ) ;
				
					
			if( stk1.top() -> right != NULL )	
				stk2.push( stk1.top() -> right ) ;
			
						
			stk1.pop() ;
		}
		
		if( row.size() > 0 )
		{
			ret.push_back( row ) ;
			row.clear() ;
		}
		
		while( !stk2.empty() )
		{
			row.push_back( stk2.top() -> val ) ;			
			
			if( stk2.top() -> right != NULL )
				stk1.push( stk2.top() -> right ) ;
			
			if( stk2.top() -> left != NULL )	
				stk1.push( stk2.top() -> left ) ;
			
			stk2.pop() ;
		}
		
		if( row.size() > 0 )
			ret.push_back( row ) ;
	}
	
	return ret ;
}

