main :: IO ()
main = print answer

answer :: Int
answer = square (sum [1 .. 100]) - sum (map square [1 .. 100])

square :: Int -> Int
square x = x * x
