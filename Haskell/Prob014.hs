import Data.Array
import Data.Tuple

main :: IO ()
main = print answer

answer :: Int
answer = snd . maximum . map swap . assocs . collatzLength $ 1000000 - 1

collatzLength :: Int -> Array Int Int
collatzLength n = arr where
    arr = array (1, n) [ (i, aux i) | i <- range (1, n) ]
    aux i
        | i == 1
            = 1
        | j <= n
            = arr ! j + 1
        | otherwise
            = aux j + 1
        where j = if even i then i `div` 2 else 3 * i + 1
