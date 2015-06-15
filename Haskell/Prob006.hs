main :: IO ()
main = print answer

answer :: Int
answer = square (sum numbers) - sum (map square numbers)

square :: Int -> Int
square n = n * n

numbers :: [Int]
numbers = [1 .. 100]
