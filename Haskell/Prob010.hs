import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = sum $ primesTo 2000000

primesTo :: Int -> [Int]
primesTo n = aux 2 a0 where
    aux i a
        | i * i > n
            = filter (a !) [i .. n]
        | a ! i
            = i : aux (i + 1) a'
        | otherwise
            = aux (i + 1) a
        where a' = a // [ (i * j, False) | j <- [i .. n `div` i] ]
    a0 = array (2, n) [ (i, True) | i <- [2 .. n] ] :: UArray Int Bool
