import Data.Array

main :: IO ()
main = print =<< answer `fmap` readFile "src/018.txt"

answer :: String -> Int
answer input = arr ! (1, 1) where
    size = length $ lines input
    arr  = array bds [ (ij, aux ij) | ij <- range bds ]
    bds  = ((1, 1), (size, size))
    aux (i, j)
        | i == size
            = get (i, j)
        | otherwise
            = get (i, j) + max (arr ! (i + 1, j)) (arr ! (i + 1, j + 1))
    get (i, j) = read . (!! (j - 1)) . words . (!! (i - 1)) . lines $ input
