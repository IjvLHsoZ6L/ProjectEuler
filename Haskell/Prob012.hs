main :: IO ()
main = print answer

answer :: Int
answer = head [ n * (n + 1) `div` 2 | n <- [1 .. ] , aux n ] where
    aux n
        | even n
            = numOfDivisor (n `div` 2) * numOfDivisor (n + 1) > 500
        | otherwise
            = numOfDivisor n * numOfDivisor ((n + 1) `div` 2) > 500

numOfDivisor :: Int -> Int
numOfDivisor = product . map (+ 1) . multiplicities

multiplicities :: Int -> [Int]
multiplicities = aux 2 where
    aux d n
        | n == 1
            = []
        | n < d * d
            = [1]
        | otherwise
            = m : aux (d + 1) (n `div` d ^ m)
        where m = multiplicity d n

multiplicity :: Int -> Int -> Int
multiplicity d n = last $ takeWhile (\ m -> n `mod` d ^ m == 0) [0 .. ]
