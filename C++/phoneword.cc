#include "phoneword.h"


Phoneword::Phoneword( long long phoneNumber ){
    phoneNum = phoneNumber;
}

Phoneword::~Phoneword(){}

vector<string> Phoneword::get(){
    vector<vector<string>> letterSet;
    stack<int> digitList = digits( phoneNum );
    
    while ( !digitList.empty() ){
        letterSet.push_back( phoneletter( digitList.top() ) );
        digitList.pop();
    }
    
    return cartesian( letterSet );
}

stack<int> Phoneword::digits( long long n ){
    stack<int> st;
    while ( n != 0 ){
        st.push( n % 10 );
        n /= 10;
    }
    return st;
}

vector<string> Phoneword::phoneletter( int n ){
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

// http://stackoverflow.com/a/31169617/1754679
vector<string> Phoneword::cartesian( vector<vector<string>> & v ){
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

string Phoneword::listToString( vector<string> &list ){
    stringstream ss; 
    for ( string s : list )
        ss << s;
    return ss.str();
}