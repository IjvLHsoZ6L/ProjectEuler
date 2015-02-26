main :: IO ()
main = print answer

answer :: Integer
answer = largestPrimeFactor 600851475143

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor = f 2 where
    f d n
        | n < d * d
            = n
        | n `mod` d == 0
            = f d (n `div` d)
        | otherwise
            = f (d + 1) n
