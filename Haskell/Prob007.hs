import Control.Monad
import Data.Array.Base
import Data.Array.ST

eratosthenes :: Int -> UArray Int Bool
eratosthenes n = runSTUArray $ do
    a <- newArray (2 , n) True
    forM_ [2 .. floor (sqrt (fromIntegral n :: Float))] $ \ i -> do
        p <- readArray a i
        when p $ forM_ [i .. n `div` i] $ \ j ->
            writeArray a (i * j) False
    return a

isPrime :: Int -> Bool
isPrime n = eratosthenes 2000000 ! n

answer :: Int
answer = find 10001 2
    where find :: Int -> Int -> Int
          find count i | isPrime i && count == 1 = i
                       | isPrime i               = find (count - 1) (i + 1)
                       | otherwise               = find count       (i + 1)

main :: IO ()
main = print answer
