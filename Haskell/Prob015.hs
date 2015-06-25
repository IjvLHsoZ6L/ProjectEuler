import Data.Array

main :: IO ()
main = print answer

answer :: Integer
answer = nRoutes 20

nRoutes :: Int -> Integer
nRoutes n = arr ! (n, n) where
    arr = array ((0, 0), (n, n)) [ ((i, j), aux i j) | (i, j) <- range ((0, 0), (n, n)) ]
    aux i j
        | i == 0
            = 1
        | j == 0
            = 1
        | otherwise
            = arr ! (i - 1, j) + arr ! (i, j - 1)
