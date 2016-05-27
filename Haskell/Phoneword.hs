module Phoneword where

import Data.Char (digitToInt)

-- Maps a number to it's cooresponding phone letters
-- 0 and 1 mapped to empty space.
phoneletter 0 = [ " " ]
phoneletter 1 = ( phoneletter 0 )
phoneletter 2 = [ "A", "B", "C" ]
phoneletter 3 = [ "D", "E", "F" ]
phoneletter 4 = [ "G", "H", "I" ]
phoneletter 5 = [ "J", "K", "L" ]
phoneletter 6 = [ "M", "N", "O" ]
phoneletter 7 = [ "P", "Q", "R", "S" ]
phoneletter 8 = [ "T", "U", "V" ]
phoneletter 9 = [ "W", "X", "Y", "Z" ]
phoneletter n = phoneletter ( mod n 10 )

type Phonenumber = Int

data Phoneword = 
	Phoneword Phonenumber

toDigits :: Int -> [Int]
toDigits = map digitToInt . show

product domain1 domain2 = [ (x,y) | x <- domain1, y <- domain2 ]

computeWords :: Phoneword -> [String]
computeWords (Phoneword phoneNum) =
	[ concat l | l <- ( sequence [ ( phoneletter digit ) | digit <- (toDigits phoneNum) ] ) ]
