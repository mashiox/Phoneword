#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

string listToString( vector<string> &list ){
    stringstream ss; 
    for ( string s : list )
        ss << s;
    return ss.str();
}

vector<string> cartesian( vector<vector<string> >& v ) {
    auto product = []( long long a, vector<string>& b ) { return a*b.size(); };
    const uint64_t N = accumulate( v.begin(), v.end(), 1LL, product );
    
    vector<string> list;
    list.reserve(N);
    vector<string> u(v.size());
    
    for( long long n = 0 ; n < N ; ++n ) {
        lldiv_t q { n, 0 };
        for( long long i = v.size()-1 ; 0 <= i ; --i ) {
            q = div( q.quot, v[i].size() );
            u[i] = v[i][q.rem];
        }
        list.push_back( listToString( u ) );
    }
    return list;
}

stack<int> digits ( long long n ){
    stack<int> st;
    while ( n != 0 ){
        st.push( n % 10 );
        n /= 10;
    }
    return st;
}

vector<string> phoneletter( int n ){
    vector<string> vec;
    switch ( n ){
        case 0:
        case 1:
            vec = { " " };
            break;
        case 2:
            vec = { "A", "B", "C" };
            break;
        case 3:
            vec = { "D", "E", "F" };
            break;
        case 4:
            vec = { "G", "H", "I" };
            break;
        case 5:
            vec = { "J", "K", "L" };
            break;
        case 6:
            vec = { "M", "N", "O" };
            break;
        case 7:
            vec = { "P", "Q", "R", "S" };
            break;
        case 8:
            vec = { "T", "U", "V" };
            break;
        case 9:
            vec = { "W", "X", "Y", "Z" };
            break;
    }
    return vec;
}

int main() {
    long long n = 23;
    vector<vector<string>> letterSet;
    
    stack<int> st = digits( n );
    while ( !st.empty() ){
        int d = st.top();
        
        
        vector<string> pl = phoneletter( d );
        letterSet.push_back( pl );
        
        st.pop();
    }
    
    vector<string> list = cartesian( letterSet );
    
    
    for ( auto idx = list.begin() ; idx != list.end() ; ++idx )
        cout << *idx << endl;
    
    return 0;
}