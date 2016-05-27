# Phoneword
Computes integers to all possible ISO/IEC 9995-8 phoneletters

0 and 1 are mapped to empty space.

## Command line usage (POSIX)

```
Uage: ./phoneword integer

integer         A phone number of arbitrary length
```

```bash
make
./phoneword 23

```

## Haskell Usage

```haskell
--
-- computeWords :: Phoneword -> [String]
-- @param ( Phoneword phoneNumber )
--
import Phoneword

-- A single phone number
let wordList = computeWord ( Phoneword 23 )

```
