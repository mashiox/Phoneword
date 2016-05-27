import System.Environment
import System.Exit
import Phoneword

main :: IO ()
main = do
	args <- getArgs
	mapM_ putStrLn ( computeWords ( Phoneword ( read (head args) :: Int ) ) )
	--let x = read (head args) :: Int
	--let l = computeWords ( Phoneword x )
	--mapM_ putStrLn l