import Control.Monad
import Data.Array.Unboxed
import Data.Array.ST.Safe

main :: IO ()
main = print answer

answer :: Int
answer = sum $ filter (primeArray !) [2 .. n]

primeArray :: UArray Int Bool
primeArray = runSTUArray $ do
    a <- newArray (2, n) True
    forM_ [2 .. floor $ sqrt (fromIntegral n :: Double)] $ \ i ->
        readArray a i >>= flip when (forM_ [i .. n `div` i] $ \ j ->
            writeArray a (i * j) False)
    return a

n :: Int
n = 2000000
