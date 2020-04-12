// Create hash map of each sorted string. Check if it is already present in map.

vector<vector<int> > Solution::anagrams(const vector<string> &A) 
{
	vector<vector<int>> ret ;
	int size = A.size() ;
	
	map<string,vector<int>> str ;
	
	for( int i = 0 ; i < size ; i++ )
	{
		vector<int> row ;
		
		string temp = A[i] ;
		
		sort( temp.begin(), temp.end() ) ;
		
		auto iter = str.find( temp ) ;
		
		if( iter == str.end() )
		{
			row.push_back( i+1 ) ;
			str.insert( pair<string, vector<int>>( temp, row ) ) ;
		}
		else
			(iter-> second).push_back( i+1 ) ;
	}
	
	auto iter = str.begin() ;
	
	for( ; iter != str.end() ; iter++ )
	{
		vector<int> row = iter -> second ;
		ret.push_back( row ) ;
	}
	
	return ret ;
}
