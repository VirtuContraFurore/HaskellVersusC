import System.IO  
import Control.Monad

-- Takes as parameter a list of Ord elements and returns a list
quickSort :: (Ord a) => [a] -> [a]

-- If list is empty return an empty list
quickSort [] = []

-- Use the head of the list as 'pivot' to recurisvely invoke quickSort
quickSort (x:xs) = quickSort smaller ++ [x] ++ quickSort larger
  where
    smaller = [a | a <- xs, a <= x]
    larger = [a | a <- xs, a > x]


readInt :: String -> Int
readInt = read

main = do  
        contents <- readFile "input.txt"
        print . quickSort . map readInt . words $ contents
