main :: IO ()
main = print answer

answer :: Int
answer = length . filter (== 0) $ dayOfFirst d [ (y, m) | y <- [1901 .. 2000], m <- [1 .. 12] ] where
    d = (1 + 365) `mod` 7

dayOfFirst :: Int -> [(Int, Int)] -> [Int]
dayOfFirst _ []             = []
dayOfFirst d ((y, m) : yms) = d : dayOfFirst ((d + nDays y m) `mod` 7) yms

nDays :: Int -> Int -> Int
nDays y m
    | m == 2 && y `mod` 400 == 0
        = 29
    | m == 2 && y `mod` 100 == 0
        = 28
    | m == 2 && y `mod` 4 == 0
        = 29
    | m == 2
        = 28
    | m `elem` [4, 6, 9, 11]
        = 30
    | otherwise
        = 31
