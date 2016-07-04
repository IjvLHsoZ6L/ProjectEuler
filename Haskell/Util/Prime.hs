module Util.Prime (primes) where

import Data.Array.Unboxed

primes :: [Int]
primes = 2 : 3 : concatMap primesBetweenSquare (zip primes (tail primes))

primesBetweenSquare :: (Int, Int) -> [Int]
primesBetweenSquare (p, q) = map fst $ filter (not . snd) $ assocs isMult where
    isMult :: UArray Int Bool
    isMult = accumArray (||) False (p * p, q * q - 1) $ zip mults (repeat True)
    mults :: [Int]
    mults = concatMap multsOf $ takeWhile (< q) primes
    multsOf :: Int -> [Int]
    multsOf i = map (i *) [(p * p - 1) `div` i + 1 .. (q * q - 1) `div` i]
