main :: IO ()
main = print answer

answer :: Integer
answer = largestPrimeFactor 600851475143

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor = aux 2 where
    aux d n
        | n < d * d
            = n
        | n `mod` d == 0
            = aux d (n `div` d)
        | otherwise
            = aux (d + 1) n
