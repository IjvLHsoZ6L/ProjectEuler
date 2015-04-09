import Control.Monad
import Data.Array.ST.Safe
import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = sum $ filter (primeArray !) [2 .. n]

n :: Int
n = 2000000

primeArray :: UArray Int Bool
primeArray = runSTUArray $ do
    a <- newArray (2, n) True
    forM_ [2 .. root n] $ \ i ->
        whenM (readArray a i) $
            forM_ [i .. n `div` i] $ \ j ->
                writeArray a (i * j) False
    return a

root :: Int -> Int
root = floor . sqrt . (fromIntegral :: Int -> Double)

whenM :: Monad m => m Bool -> m () -> m ()
whenM mb mu = do
    b <- mb
    when b mu
