import Control.Applicative
import Data.Char

main :: IO ()
main = do
    xs <- map digitToInt . concat . lines <$> readFile "Prob008.txt"
    print $ answer xs

answer :: [Int] -> Int
answer xs = maximum $ map product $ thirteens xs

thirteens :: [a] -> [[a]]
thirteens xs
    | length xs >= 13
        = take 13 xs : thirteens (tail xs)
    | otherwise
        = []
