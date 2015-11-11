main :: IO ()
main = putStrLn answer

answer :: String
answer = lexico (1000000 - 1) "0123456789"

lexico :: Int -> [a] -> [a]
lexico 0 [] = []
lexico _ [] = error "lexico: something wrong"
lexico n xs = x : lexico r ys where
    l      = length xs
    (q, r) = quotRem n (product [1 .. l - 1])
    x      = xs !! q
    ys     = take q xs ++ drop (q + 1) xs
