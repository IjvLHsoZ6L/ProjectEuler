import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = sum [ n | n <- [1 .. limit], not $ isSum ! n ]

limit :: Int
limit = 28123

isSum :: UArray Int Bool
isSum = accumArray (flip const) False (1, limit)
    [ (i + j, True)
    | i <- as
    , j <- takeWhile (\ j -> j <= i && i + j <= limit) as
    ] where as = filter isAbundant [1 .. limit]

isAbundant :: Int -> Bool
isAbundant n = sumOfProperDivisors n > n

sumOfProperDivisors :: Int -> Int
sumOfProperDivisors n
    = product [ (p ^ (i + 1) - 1) `div` (p - 1) | (p, i) <- decompose $ factors n ] - n

decompose :: Eq a => [a] -> [(a, Int)]
decompose []           = []
decompose xs @ (y : _) = (y, length ys) : decompose zs where
    (ys, zs) = span (== y) xs

factors :: Integral a => a -> [a]
factors n = search n 2 where
    search m d
        | m == 1
            = []
        | m < d * d
            = [m]
        | r == 0
            = d : search q d
        | otherwise
            = search m (d + 1)
        where (q, r) = quotRem m d
