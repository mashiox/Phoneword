# Phoneword
Computes integers to all possible ISO/IEC 9995-8 phoneletters

0 and 1 are mapped to empty space.

Note, this solution is bound by the range of the int primitive.

## Command line usage (POSIX)

```
Uage: ./phoneword [ -h | integer ]

-h              Display this help

integer         A phone number of arbitrary length
```

## Java Main Usage

```bash
java -jar Phoneword.jar [integer value]
java -jar Phoneword.jar 456
```

## Java Usage

```java

// A single phone number
int n = 23;
Phoneword p = new Phoneword( n );
ArrayList<String> wordList = p.get();
for ( String word : wordList ){
    System.out.println( word );
}

// A set of phone numbers
int[] nums = [ 55578931, 45876, 911 ]
for ( int phoneNumber : nums ){
    Phoneword p = new Phoneword( phoneNumber );
    ArrayList<String> wordList = p.get();
    for ( String word : wordList ){
        System.out.println( word );
    }
    System.out.println();
} 

```
