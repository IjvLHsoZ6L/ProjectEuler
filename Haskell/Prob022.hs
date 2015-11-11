import Data.Char
import Data.List

main :: IO ()
main = print . answer =<< readFile "src/022.txt"

answer :: String -> Int
answer input = sum [ i * worth name | (i, name) <- zip [1 .. ] names ] where
    names = sort $ words input

worth :: String -> Int
worth name = sum [ ord c - ord 'A' + 1 | c <- name ]
