import Control.Monad
import Data.Array.ST.Safe
import Data.Array.Unboxed

main :: IO ()
main = print answer

answer :: Int
answer = primeList !! 10001

primeList :: [Int]
primeList = filter (primeArray !) [2 .. n]

primeArray :: UArray Int Bool
primeArray = runSTUArray $ do
    a <- newArray (2, n) True
    sequence_
        [ (readArray a i >>=) $ flip when $ sequence_
            [ writeArray a (i * j) False
            | j <- [i .. n `div` i]
            ]
        | i <- [2 .. floor $ sqrt (fromIntegral n :: Double)]
        ]
    return a

n :: Int
n = 2000000
