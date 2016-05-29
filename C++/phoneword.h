#ifndef PHONEWORD_H
#define PHONEWORD_H

#include <stack>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <sstream>

using namespace std;

class Phoneword
{
public:

    Phoneword( long long phoneNumber );
    
    ~Phoneword();
    
    vector<string> get();
    
private:
    
    long long phoneNum;
    
    stack<int> digits( long long n );
    vector<string> phoneletter( int n );
    vector<string> cartesian( vector<vector<string>> & v );
    string listToString( vector<string> &list );
};

#endif