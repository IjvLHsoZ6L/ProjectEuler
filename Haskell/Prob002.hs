fibonacci :: [Int]
fibonacci = fib_rec 1 2
    where fib_rec a b = a : fib_rec b (a + b)

answer :: Int
answer = sum [ x | x <- takeWhile (<= 4000000) fibonacci , even x ]

main :: IO ()
main = print answer
