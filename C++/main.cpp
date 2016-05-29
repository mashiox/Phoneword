#include <iostream>
#include <vector>
#include "phoneword.h"

using namespace std;

void usage(){
    cout << "Uage: ./phoneword [ -h | integer ]" << endl;
    cout << endl;
    cout << "-h|--help       Display this help" << endl;
    cout << endl;
    cout << "integer         A phone number of arbitrary length" << endl;
}

int main( int argc, char *argv[] ){
    
    if ( argc == 1 ){
        usage();
        return 0;
    }
    
    if ( string(argv[1]) == "-h" || string(argv[1]) == "--help" ){
        usage();
        return 0;
    }
    
    long long param;
    vector<string> wordList;
    string::size_type sz = 0;
    for ( int idx = 1; idx < argc ; idx++ ){
        param = stoll( argv[idx], &sz, 0 );
        Phoneword *p = new Phoneword( param );
        wordList = p->get();
        
        for ( string word : wordList ){
            cout << word << endl;
        }
        cout << endl;
    }
    return 0;
}