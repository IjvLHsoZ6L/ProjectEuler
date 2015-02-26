main :: IO ()
main = print answer

answer :: Int
answer = sum [ x | x <- takeWhile (<= 4000000) fibonacci , even x ]

fibonacci :: [Int]
fibonacci = f 1 2 where f a b = a : f b (a + b)
