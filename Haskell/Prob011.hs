main :: IO ()
main = print . answer =<< readFile "src/011.txt"

answer :: String -> Int
answer input = maximum $ map product $ horiz ++ verti ++ diag1 ++ diag2 where
    horiz  = [ [ matrix i (j + k) | k <- ks ] | i <- is , j <- js' ]
    verti  = [ [ matrix (i + k) j | k <- ks ] | i <- is' , j <- js ]
    diag1  = [ [ matrix (i + k) (j + k) | k <- ks ] | i <- is' , j <- js' ]
    diag2  = [ [ matrix (i + k) (j + 4 - k - 1) | k <- ks ] | i <- is' , j <- js' ]
    height = length . lines $ input
    width  = length . words . head . lines $ input
    is     = take height [0 .. ]
    is'    = [0 .. height - 4]
    js     = take width [ 0 .. ]
    js'    = [0 .. width - 4]
    ks     = take 4 [0 .. ]
    matrix i j = read . (!! j) . words . (!! i) . lines $ input
