main :: IO ()
main = print answer

answer :: Int
answer = head
    [ a * b * c
    | a <- [1 .. 1000 `div` 3]
    , b <- [a .. (1000 - a) `div` 2]
    , let c = 1000 - a - b
    , pythagorean a b c
    ]

pythagorean :: Int -> Int -> Int -> Bool
pythagorean a b c = a * a + b * b == c * c
