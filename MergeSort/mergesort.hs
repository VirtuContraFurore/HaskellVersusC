import System.IO  
import Control.Monad

mergeSort :: (Ord a) => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort firstHalf) (mergeSort secondHalf)
  where
    (firstHalf, secondHalf) = splitAt (length xs `div` 2) xs

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x <= y = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys

readInt :: String -> Int
readInt = read

main = do  
        contents <- readFile "input.txt"
        print . mergeSort . map readInt . words $ contents
