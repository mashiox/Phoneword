# Phoneword
Computes integers to all possible ISO/IEC 9995-8 phoneletters

0 and 1 are mapped to empty space.

## Command line usage (POSIX)

```
Uage: ./phoneword [ -h | integer ]

-h              Display this help

integer         A phone number of arbitrary length
```

## Python Main Usage

```bash
python main.py [integer value]
python main.py 456
```

## Python Usage

```python
#
# Phoneword( phoneNumber )
# @param phoneNumber: int, phone number to transform
#
from phoneword import Phoneword

# A single phone number
print( Phoneword( 555879213 ) )

# A set of phone numbers
nums = [ 55578931, 45876, 911 ]
for x in nums:
    print( Phoneword( x ) )
```
