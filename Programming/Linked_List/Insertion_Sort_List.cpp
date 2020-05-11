// Create new node for sorted list.
// Insert nodes at correct position and delete old node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *insertNode( ListNode *curr, ListNode *head )
{
	if( head == NULL )
	{
		ListNode *newnode = new ListNode( curr -> val ) ;
		head = newnode ;
		
		return head ;
	}
	
	else if( curr -> val < head -> val )
	{
		ListNode *newnode = new ListNode( curr -> val ) ;
		newnode -> next = head ;
		
		return newnode ;
	}
	else
	{
		ListNode *ret = head ;
		
		// Previous node in traversal
		ListNode *prev = head ;
		while( head != NULL && curr -> val > head -> val )
		{
			prev = head ;
			head = head -> next ;
		}
		
		// Create new node and add it in list
		ListNode *newnode = new ListNode( curr -> val ) ;
		
		newnode -> next = head ;
		prev -> next = newnode ;
		
		return ret ;
	}
}

ListNode *insSort( ListNode *A )
{
	if( A == NULL )
		return A ;
	
	ListNode *newhead = NULL ;
		
	ListNode *curr = A ;
	
	while( curr != NULL )
	{
		newhead = insertNode( curr, newhead ) ;
		
		ListNode *del = curr ;
		curr = curr -> next ;
		delete del ;
	}
	
	return newhead ;
}
 
ListNode* Solution::insertionSortList(ListNode* A) 
{
    return insSort( A ) ;
}
