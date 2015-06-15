main :: IO ()
main = print answer

answer :: Int
answer = sum $ filter even $ takeWhile (<= 4000000) fibonacci

fibonacci :: [Int]
fibonacci = aux 0 1 where
    aux a b = a : aux b (a + b)
