// https://www.interviewbit.com/problems/add-one-to-number/

// Take care of Position and multiplying with 10.

vector<int> Solution::plusOne(vector<int> &A) 
{
    int size_A = A.size() ;
    
    if( size_A > 0 )
    {
        int carry = 0 ;
        for( int i = ( size_A-1) ; i >= 0 ; i-- )
        {
            int num = A[ i ] ;
            
            if( i == ( size_A -1))
                num = num + 1 ;
            else
                if( carry != 0 )
                    num = num + carry ;
            
            carry = 0 ;
            
            if( num > 9 )
            {
                num = num % 10 ;
                carry = 1 ;
            }
            
            A[ i ] = num ;
        }
        
        // If new number has overflown the number of digits.
        if( carry != 0 )
        {
            vector<int> new_A ;
            new_A.push_back(carry);
            
            // Copy old vector
            copy( A.begin(), A.end(), back_inserter(new_A));
            
            return new_A ;
        }
        
        // If MSV is/are 0
        if( A[0] == 0 )
        {
            int i ;
            for( i = 0 ; i < size_A && A[i] == 0 ; i++ );
            
            vector<int> new_A ;
            copy( A.begin() + i, A.end() , back_inserter(new_A));
            
            return new_A  ;
        }
        
        return A ;
    }
    else
    {
        vector<int> null ;
        null.push_back(1);
        
        return null ;
    }
}
