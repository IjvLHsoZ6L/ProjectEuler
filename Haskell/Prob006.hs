square :: Int -> Int
square x = x * x

answer :: Int
answer = square (sum [1 .. 100]) - sum (map square [1 .. 100])

main :: IO ()
main = print answer
