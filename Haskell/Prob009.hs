main :: IO ()
main = print answer

answer :: Int
answer = head [ a * b * c | (a , b , c) <- abcs , pythagorean a b c ] where
    abcs = [ (a , b , s - a - b) | a <- [1 .. ] , b <- [a + 1 .. (s - a - 1) `div` 2] ]
    s = 1000

pythagorean :: Int -> Int -> Int -> Bool
pythagorean a b c = a * a + b * b == c * c
