// Used extra space to combine all elements from all row, then finding median.

int Solution::findMedian(vector<vector<int> > &A) 
{
    vector<int> all_num ;
    
    int size1 = A.size() ;
    int size2 = A[ 0 ].size() ;
    
    for( int i = 0 ; i < size1 ; i++ )
    {
        for( int j = 0 ; j < size2 ; j++ )
        {
            all_num.push_back( A[ i ][ j ] ) ;
        }
    }
    
    int size_all = all_num.size() ;
    
    sort( all_num.begin(), all_num.begin() + size_all ) ;
    
    return all_num[ ( size_all/2 )] ;
}
