# Phoneword
Computes integers to all possible ISO/IEC 9995-8 phoneletters

0 and 1 are mapped to empty space.

Note, this solution is bound by the range of the int primitive.

## Command line usage (POSIX)

```
Uage: ./phoneword [ -h | integer ]

-h|--help       Display this help

integer         A phone number of arbitrary length
```

## C++ Usage

```c++

// A single phone number
long long n = 23;
Phoneword p( n );
vector<string> wordList = p.get();
for ( string word : wordList ){
    cout << word << endl;
}

// A set of phone numbers
// it's possible... no more tonight tho. 

```
