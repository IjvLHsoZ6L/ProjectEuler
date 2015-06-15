module Util.Prime where

import Control.Monad
import Data.Array.Unboxed
import Data.Array.ST

primeListTo :: Int -> [Int]
primeListTo n = filter (primeArrayTo n !) $ range (2 , n)

primeArrayTo :: Int -> UArray Int Bool
primeArrayTo n = runSTUArray $ do
    a <- newArray (2 , n) True
    forM_ [2 .. rootN] $ \ i ->
        ifM_ (readArray a i) $
            forM_ [i .. n `div` i] $ \ j ->
                writeArray a (i * j) False
    return a
    where rootN = floor $ sqrt (fromIntegral n :: Double)

ifM_ :: Monad m => m Bool -> m () -> m ()
ifM_ mb action = do
    b <- mb
    when b action
