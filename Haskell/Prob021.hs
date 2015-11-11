main :: IO ()
main = print answer

answer :: Int
answer = sum $ filter isAmicable [2 .. 10000 - 1]

isAmicable :: Int -> Bool
isAmicable a = a /= b && sumOfDivsors b == a where
    b = sumOfDivsors a

sumOfDivsors :: Int -> Int
sumOfDivsors a = product [ (p ^ (n + 1) - 1) `div` (p - 1) | (p, n) <- decompose $ factors a ] - a

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
