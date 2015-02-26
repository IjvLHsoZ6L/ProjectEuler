digitsOf :: Int -> [Int]
digitsOf 0 = []
digitsOf n = (n `mod` 10) : digitsOf (n `div` 10)

palindromic :: Int -> Bool
palindromic n = digitsOf n == reverse (digitsOf n)

answer :: Int
answer = find 0 b
    where a = 100
          b = 999
          find acc i
              | i < a || i * b <= acc = acc
              | otherwise             = find (find' acc i b) (i - 1)
          find' acc i j
              | j < i || i * j <= acc = acc
              | palindromic (i * j)   = i * j
              | otherwise             = find' acc i (j - 1)

main :: IO ()
main = print answer

