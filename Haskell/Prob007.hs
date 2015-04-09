import Control.Monad
import Data.Array.ST.Safe
import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = primeList !! 10001

primeList :: [Int]
primeList = filter (primeArray !) (indices primeArray)

primeArray :: UArray Int Bool
primeArray = runSTUArray $ do
    a <- newArray (2, n) True
    forM_ [2 .. root n] $ \ i ->
        whenM (readArray a i) $
            forM_ [i .. n `div` i] $ \ j ->
                writeArray a (i * j) False
    return a
    where n = 2000000

root :: Int -> Int
root = floor . sqrt . (fromIntegral :: Int -> Double)

whenM :: Monad m => m Bool -> m () -> m ()
whenM mb mu = do
    b <- mb
    when b mu
