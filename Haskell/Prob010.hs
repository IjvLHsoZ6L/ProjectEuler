import Control.Monad
import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = sum $ primesTo 2000000

primesTo :: Int -> [Int]
primesTo n = aux 2 a0 where
    a0 = array (2, n) [ (i, True) | i <- [2 .. n] ] :: UArray Int Bool
    aux i a
        | i > n
            = []
        | a ! i && i * i <= n
            = i : aux (i + 1) a'
        | a ! i
            = i : aux (i + 1) a
        | otherwise
            = aux (i + 1) a
        where a' = a // [ (i * j, False) | j <- [i .. n `div` i] ]
