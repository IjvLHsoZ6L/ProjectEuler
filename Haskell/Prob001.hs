main :: IO ()
main = print answer

answer :: Int
answer = sum $ filter isMultipleOf3or5 below1000 where
    isMultipleOf3or5 n = n `mod` 3 == 0 || n `mod` 5 == 0
    below1000 = takeWhile (< 1000) [1 .. ]
