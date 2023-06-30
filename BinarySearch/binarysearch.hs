import System.IO  
import Control.Monad

binarySearch :: (Ord a) => [a] -> Maybe Int
binarySearch (x:arr) = binarySearch' 0 (length arr - 1)
  where
    binarySearch' left right
      | left > right = Nothing
      | otherwise = case compare (arr !! mid) x of
                      EQ -> Just mid
                      LT -> binarySearch' (mid + 1) right
                      GT -> binarySearch' left (mid - 1)
      where mid = left + (right - left) `div` 2

readInt :: String -> Int
readInt = read

main = do  
        contents <- readFile "input.txt"
        print . binarySearch . map readInt . words $ contents

