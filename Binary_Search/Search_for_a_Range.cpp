// Using binary search to search for first and last occurence.

int first( const vector<int> &arr, int low, int high, int x ) 
{ 
	int n = arr.size() ;

	if(high >= low) 
	{ 
		int mid = (low+high)/2; 
		
		if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x) 
			return mid ;
			
		else if(x > arr[mid]) 
			return first(arr, (mid + 1), high, x ); 
			
		else
			return first(arr, low, (mid -1), x); 
	} 
	return -1; 
} 


int last( const vector<int> &arr, int low, int high, int x ) 
{ 
	int n = arr.size() ;

	if (high >= low) 
	{ 
		int mid = ( low + high ) /2 ;
		
		if (( mid == n-1 || x < arr[mid+1]) && arr[mid] == x) 
			return mid ;
			
		else if (x < arr[mid]) 
			return last(arr, low, (mid -1), x ) ; 
			
		else
			return last(arr, (mid + 1), high, x ); 
	} 
	return -1; 
} 

vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
	int pos = -1 ;
	
	vector<int> ret ;
	
	pos = first( A, 0, A.size() -1, B ) ;
	ret.push_back( pos ) ;
	
	pos = last( A, 0, A.size() -1, B ) ;
	ret.push_back( pos ) ;
	
	return ret ;
}
