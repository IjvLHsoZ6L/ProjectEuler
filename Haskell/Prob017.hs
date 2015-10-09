main :: IO ()
main = print answer

answer :: Int
answer = sum $ map (sum . map length . words . show') [1 .. 1000]

show' :: Int -> String
show' 1 = "one"
show' 2 = "two"
show' 3 = "three"
show' 4 = "four"
show' 5 = "five"
show' 6 = "six"
show' 7 = "seven"
show' 8 = "eight"
show' 9 = "nine"
show' 10 = "ten"
show' 11 = "eleven"
show' 12 = "twelve"
show' 13 = "thirteen"
show' 14 = "fourteen"
show' 15 = "fifteen"
show' 16 = "sixteen"
show' 17 = "seventeen"
show' 18 = "eighteen"
show' 19 = "nineteen"
show' 20 = "twenty"
show' 30 = "thirty"
show' 40 = "forty"
show' 50 = "fifty"
show' 60 = "sixty"
show' 70 = "seventy"
show' 80 = "eighty"
show' 90 = "ninety"
show' 1000 = "one thousand"
show' n
    | n < 100
        = show' (n - n1) ++ " " ++ show' n1
    | n2 == 0
        = show' (n `div` 100) ++ " hundred"
    | otherwise
        = show' (n - n2) ++ " and " ++ show' n2
    where
        n1 = n `mod` 10
        n2 = n `mod` 100
