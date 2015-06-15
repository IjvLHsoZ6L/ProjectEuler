main :: IO ()
main = print answer

answer :: Int
answer = maximum $ filter palindrome [ m * n | m <- threeDigitNumber , n <- threeDigitNumber ]

threeDigitNumber :: [Int]
threeDigitNumber = [100 .. 999]

palindrome :: Int -> Bool
palindrome n = show n == reverse (show n)
