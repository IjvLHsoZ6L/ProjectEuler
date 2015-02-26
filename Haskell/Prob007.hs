import Control.Monad
import Data.Array.ST.Safe
import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = primeList !! 10001

primeList :: [Int]
primeList = filter (\ i -> primeArray ! i) [2 .. n]

primeArray :: UArray Int Bool
primeArray = runSTUArray $ do
    a <- newArray (2, n) True
    forM_ [2 .. floor $ sqrt (fromIntegral n :: Double)] $ \ i ->
        readArray a i >>= flip when (forM_ [i .. n `div` i] $ \ j ->
            writeArray a (i * j) False)
    return a

n :: Int
n = 2000000
