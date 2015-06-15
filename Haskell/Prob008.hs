import Data.Char

main :: IO ()
main = print . answer =<< readFile "src/008.txt"

answer :: String -> Int
answer = maximum . map product . subseqs 13 . map digitToInt . concat . words

subseqs :: Int -> [a] -> [[a]]
subseqs n xs
    | length xs >= n
        = take n xs : subseqs n (tail xs)
    | otherwise
        = []
