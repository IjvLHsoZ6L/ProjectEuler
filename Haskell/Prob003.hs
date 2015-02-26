largestPrimeFactor :: Integer -> Integer
largestPrimeFactor = lpf_rec 2
    where lpf_rec d n | n < d * d      = n
                      | n `mod` d == 0 = lpf_rec d (n `div` d)
                      | otherwise      = lpf_rec (d + 1) n

answer :: Integer
answer = largestPrimeFactor 600851475143

main :: IO ()
main = print answer
