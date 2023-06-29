import System.IO  
import Control.Monad

selectionSort :: (Ord a) => [a] -> [a]
selectionSort [] = []
selectionSort xs = let (minElem, rest) = removeMin xs
                   in minElem : selectionSort rest
  where
    removeMin [x] = (x, [])
    removeMin (x:xs)
      | x <= minElem = (x, minElem:rest)
      | otherwise = (minElem, x:rest)
      where (minElem, rest) = removeMin xs

readInt :: String -> Int
readInt = read

main = do  
        contents <- readFile "input.txt"
        print . selectionSort . map readInt . words $ contents
