import Control.Monad
import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = primesTo 2000000 !! 10001

primesTo :: Int -> [Int]
primesTo n = aux 2 a0 where
    aux :: Int -> UArray Int Bool -> [Int]
    aux i a
        | i > n
            = []
        | a ! i && i * i > n
            = i : aux (i + 1) a
        | a ! i
            = i : aux (i + 1) a'
        | otherwise
            = aux (i + 1) a
        where a' = a // [ (i * j, False) | j <- [i .. n `div` i] ]
    a0 :: UArray Int Bool
    a0 = array (2, n) [ (i, True) | i <- [2 .. n] ]
