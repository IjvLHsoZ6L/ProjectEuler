main :: IO ()
main = print answer

answer :: Int
answer = f 0 b where
    a = 100
    b = 999
    f m i
        | i < a || i * b <= m
            = m
        | otherwise
            = f (g m i b) (i - 1)
    g m i j
        | j < i || i * j <= m
            = m
        | palindromic (i * j)
            = i * j
        | otherwise
            = g m i (j - 1)

palindromic :: Int -> Bool
palindromic n = digitsOf n == reverse (digitsOf n)

digitsOf :: Int -> [Int]
digitsOf 0 = []
digitsOf n = (n `mod` 10) : digitsOf (n `div` 10)
