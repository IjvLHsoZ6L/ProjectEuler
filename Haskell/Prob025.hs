main :: IO ()
main = print answer

answer :: Int
answer = snd $ head $ filter ((>= 10 ^ (1000 - 1 :: Int)) . fst) $ zip fibonacci [1 .. ]

fibonacci :: [Integer]
fibonacci = fibRec 1 1 where
    fibRec a b = a : fibRec b (a + b)
