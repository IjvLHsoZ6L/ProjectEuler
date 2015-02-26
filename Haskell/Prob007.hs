import Data.Array.ST.Safe
import Data.Array.Unboxed

n :: Int
n = 2000000

primeArray :: UArray Int Bool
primeArray = runSTUArray $ do
    a <- newArray (2, n) True
    sequence_
        [ writeArray a (i * j) False
        | i <- takeWhile (\ i -> i * i <= n) [2 .. ]
        , j <- takeWhile (\ j -> i * j <= n) [i .. ]
        ]
    return a

primeList :: [Int]
primeList = filter (\ i -> primeArray ! i) [2 .. n]

answer :: Int
answer = primeList !! 10001

main :: IO ()
main = print answer
